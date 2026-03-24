import { promises as fs } from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const projectRoot = path.resolve(__dirname, '..');
const publicDir = path.join(projectRoot, 'public');
const outputPath = path.join(projectRoot, 'src', 'data', 'contentIndex.json');

const byName = (a, b) => a.localeCompare(b, 'en', { numeric: true, sensitivity: 'base' });

async function listFiles(directoryPath) {
  try {
    const entries = await fs.readdir(directoryPath, { withFileTypes: true });
    return entries
      .filter((entry) => entry.isFile())
      .map((entry) => entry.name)
      .sort(byName);
  } catch (error) {
    if (error.code === 'ENOENT') {
      return [];
    }
    throw error;
  }
}

async function listDirectories(directoryPath) {
  try {
    const entries = await fs.readdir(directoryPath, { withFileTypes: true });
    return entries
      .filter((entry) => entry.isDirectory())
      .map((entry) => entry.name)
      .sort(byName);
  } catch (error) {
    if (error.code === 'ENOENT') {
      return [];
    }
    throw error;
  }
}

async function generateContentIndex() {
  const dayFolders = (await listDirectories(publicDir)).filter((folder) => /^Day\d{2}$/.test(folder));

  const days = {};
  for (const dayFolder of dayFolders) {
    days[dayFolder] = await listFiles(path.join(publicDir, dayFolder));
  }

  const leetcode = await listFiles(path.join(publicDir, 'Leetcode'));
  const problems = await listFiles(path.join(publicDir, 'Problems'));

  const topicsRoot = path.join(publicDir, 'Topics');
  const topicFolders = await listDirectories(topicsRoot);
  const topics = {};

  for (const topicFolder of topicFolders) {
    topics[topicFolder] = await listFiles(path.join(topicsRoot, topicFolder));
  }

  const index = {
    generatedAt: new Date().toISOString(),
    days,
    leetcode,
    problems,
    topics,
  };

  await fs.mkdir(path.dirname(outputPath), { recursive: true });
  await fs.writeFile(outputPath, `${JSON.stringify(index, null, 2)}\n`, 'utf8');

  console.log(`Generated ${path.relative(projectRoot, outputPath)}`);
}

generateContentIndex().catch((error) => {
  console.error('Failed to generate content index:', error);
  process.exitCode = 1;
});
