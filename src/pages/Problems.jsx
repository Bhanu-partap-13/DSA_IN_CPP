import React, { useState, useEffect } from 'react';
import { motion } from 'framer-motion';
import { FiTarget } from 'react-icons/fi';
import CodeBlock from '../components/CodeBlock';
import Loader from '../components/Loader';
import contentIndex from '../data/contentIndex.json';

const Problems = () => {
  const [files, setFiles] = useState([]);
  const [selectedFile, setSelectedFile] = useState(null);
  const [fileContent, setFileContent] = useState('');
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    loadFiles();
  }, []);

  useEffect(() => {
    if (selectedFile) {
      loadFileContent(selectedFile);
    }
  }, [selectedFile]);

  const loadFiles = () => {
    const problemFiles = (contentIndex?.problems || []).filter((fileName) => fileName.toLowerCase().endsWith('.cpp'));
    setFiles(problemFiles);
    if (problemFiles.length > 0) {
      setSelectedFile(problemFiles[0]);
    }
    setLoading(false);
  };

  const loadFileContent = async (fileName) => {
    if (!fileName) return;
    
    try {
      const response = await fetch(`/Problems/${fileName}?t=${Date.now()}`, {
        cache: 'no-store',
      });
      if (!response.ok) {
        throw new Error(`HTTP error! status: ${response.status}`);
      }
      const content = await response.text();
      setFileContent(content);
    } catch (error) {
      console.error('Error loading file content:', error);
      setFileContent(`// Error loading file: ${fileName}\n// Please check if the file exists at /Problems/${fileName}`);
    }
  };

  const getProblemName = (fileName) => {
    return fileName
      .replace('.cpp', '')
      .replace(/([A-Z])/g, ' $1')
      .replace(/^./, (str) => str.toUpperCase())
      .trim();
  };

  if (loading) {
    return <Loader />;
  }

  return (
    <div className="min-h-screen bg-gray-50 dark:bg-gray-900">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-8">
        {/* Header */}
        <motion.div
          initial={{ opacity: 0, y: -20 }}
          animate={{ opacity: 1, y: 0 }}
          className="mb-8 text-center"
        >
          <div className="inline-flex items-center justify-center w-16 h-16 rounded-full bg-gradient-to-br from-green-500 to-teal-500 text-white text-2xl mb-4">
            <FiTarget />
          </div>
          <h1 className="text-3xl md:text-4xl font-bold text-gray-900 dark:text-white mb-2">
            Practice Problems
          </h1>
          <p className="text-gray-600 dark:text-gray-400">
            {files.length} {files.length === 1 ? 'problem' : 'problems'} to enhance your skills
          </p>
        </motion.div>

        {files.length === 0 ? (
          <motion.div
            initial={{ opacity: 0 }}
            animate={{ opacity: 1 }}
            className="text-center py-20"
          >
            <p className="text-gray-500 dark:text-gray-400 text-lg">
              No problems available yet. Check back soon!
            </p>
          </motion.div>
        ) : (
          <div className="grid grid-cols-1 lg:grid-cols-4 gap-6">
            {/* Problem List */}
            <motion.div
              initial={{ opacity: 0, x: -20 }}
              animate={{ opacity: 1, x: 0 }}
              className="lg:col-span-1"
            >
              <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-4 sticky top-20">
                <h2 className="text-lg font-semibold text-gray-900 dark:text-white mb-4">
                  Problems
                </h2>
                <div className="space-y-2 max-h-[calc(100vh-200px)] overflow-y-auto">
                  {files.map((file) => (
                    <button
                      key={file}
                      onClick={() => setSelectedFile(file)}
                      className={`w-full text-left px-3 py-2 rounded-lg text-sm transition-colors ${
                        selectedFile === file
                          ? 'bg-green-50 dark:bg-green-900/20 text-green-600 dark:text-green-400 font-medium'
                          : 'text-gray-700 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-700'
                      }`}
                    >
                      <span className="block truncate">{getProblemName(file)}</span>
                    </button>
                  ))}
                </div>
              </div>
            </motion.div>

            {/* Code Display */}
            <motion.div
              initial={{ opacity: 0, x: 20 }}
              animate={{ opacity: 1, x: 0 }}
              className="lg:col-span-3"
            >
              <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-6">
                <h2 className="text-xl font-semibold text-gray-900 dark:text-white mb-4">
                  {getProblemName(selectedFile)}
                </h2>
                {fileContent ? (
                  <CodeBlock code={fileContent} language="cpp" fileName={selectedFile} />
                ) : (
                  <div className="text-center py-12 text-gray-500 dark:text-gray-400">
                    Select a problem to view its solution
                  </div>
                )}
              </div>
            </motion.div>
          </div>
        )}
      </div>
    </div>
  );
};

export default Problems;
