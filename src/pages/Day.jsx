import React, { useState, useEffect } from "react";
import { useParams, Link } from "react-router-dom";
import ReactMarkdown from "react-markdown";
import { FaFileCode, FaFileAlt, FaDownload, FaTerminal, FaRegStickyNote, FaExpand, FaCompress, FaSearchPlus, FaSearchMinus, FaGithub, FaStar, FaTimes } from "react-icons/fa";
import contentIndex from "../data/contentIndex.json";
import Loader from "../components/Loader";
import CodeBlock from "../components/CodeBlock";

const fetchFileContent = async (dayFolder, fileName) => {
  try {
    const response = await fetch(`/${dayFolder}/${fileName}?t=${Date.now()}`, {
      cache: "no-store",
    });
    if (!response.ok) {
      throw new Error(`File not found or error fetching: ${dayFolder}/${fileName} (status: ${response.status})`);
    }
    const textContent = await response.text();
    return textContent;
  } catch (error) {
    if (fileName.toLowerCase().endsWith(".md")) {
      return `# Markdown Content for ${fileName}\n\n*File not found at /${dayFolder}/${fileName}. Please ensure it exists in the public directory.*`;
    } else if (fileName.toLowerCase().endsWith(".cpp")) {
      return `// C++ Code for ${fileName}\n// File not found at /${dayFolder}/${fileName}. Please ensure it exists in the public directory.\n#include <iostream>\n\nint main() {\n    std::cout << \"File not found for ${fileName}!\" << std::endl;\n    return 1;\n}`;
    }
    return `Content for ${fileName}\n*File not found at /${dayFolder}/${fileName}. Please ensure it exists in the public directory.*`;
  }
};

const getFileIcon = (fileName) => {
  if (fileName.toLowerCase().endsWith(".cpp")) return <FaFileCode className="inline mr-1 text-blue-500 dark:text-blue-400" />;
  if (fileName.toLowerCase().endsWith(".md")) return <FaFileAlt className="inline mr-1 text-purple-500 dark:text-purple-400" />;
  if (fileName.toLowerCase().endsWith(".exe")) return <FaFileAlt className="inline mr-1 text-green-500 dark:text-green-400" />;
  if (fileName.toLowerCase().endsWith(".txt")) return <FaFileAlt className="inline mr-1 text-yellow-500 dark:text-yellow-400" />;
  return <FaFileAlt className="inline mr-1 text-gray-500 dark:text-gray-400" />;
};

const getFileType = (fileName) => {
  if (fileName.toLowerCase().endsWith(".md")) return "md";
  if (fileName.toLowerCase().endsWith(".cpp")) return "cpp";
  if (fileName.toLowerCase().endsWith(".txt")) return "txt";
  return "other";
};

const Day = () => {
  const { dayId } = useParams();
  const dayNum = parseInt(dayId, 10);
  const dayFolder = `Day${dayId}`;

  const [files, setFiles] = useState([]);
  const [selectedFileIdx, setSelectedFileIdx] = useState(0);
  const [fileContent, setFileContent] = useState("");
  const [copied, setCopied] = useState(false);
  const [notes, setNotes] = useState("");
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");
  const [isFullSize, setIsFullSize] = useState(false);
  const [zoomLevel, setZoomLevel] = useState(150);
  const [showStarPrompt, setShowStarPrompt] = useState(false);

  const githubRepoUrl = "https://github.com/Bhanu-partap-13/30-Days-Of-CPP";

  useEffect(() => {
    const fileList = contentIndex?.days?.[dayFolder] || [];
    setFiles(fileList);
    setSelectedFileIdx(0);
    setNotes(localStorage.getItem(`notes-day${dayId}`) || "");
    setError("");

    if (fileList.length === 0) {
      setFileContent("");
      setLoading(false);
      setError(`No files are listed for ${dayFolder}. Ensure files exist in /public/${dayFolder}/ and regenerate the content index.`);
    }
  }, [dayId, dayFolder]);

  useEffect(() => {
    const shouldHidePrompt = localStorage.getItem("hide-github-star-prompt") === "true";
    if (shouldHidePrompt) {
      setShowStarPrompt(false);
      return;
    }

    const popupTimer = window.setTimeout(() => {
      setShowStarPrompt(true);
    }, 650);

    return () => window.clearTimeout(popupTimer);
  }, [dayId]);

  useEffect(() => {
    if (files.length > 0 && files[selectedFileIdx]) {
      setLoading(true);
      setError("");
      fetchFileContent(dayFolder, files[selectedFileIdx])
        .then(content => {
          setFileContent(content);
          setLoading(false);
        })
        .catch((fetchError) => {
          setFileContent("");
          setLoading(false);
          console.error("Fetch error for", `${dayFolder}/${files[selectedFileIdx]}` , fetchError);
          setError(`Failed to load: ${files[selectedFileIdx]}. Ensure it exists at /public/${dayFolder}/${files[selectedFileIdx]}.`);
        });
    } else if (files.length === 0 && !error) {
      setError(`No files to display for ${dayFolder}.`);
      setLoading(false);
    }
  }, [selectedFileIdx, files, dayFolder, error]);

  useEffect(() => {
    if (!isFullSize) {
      setZoomLevel(150);
    }

    const originalOverflow = document.body.style.overflow;
    if (isFullSize || showStarPrompt) {
      document.body.style.overflow = "hidden";
    }

    const onKeyDown = (event) => {
      if (event.key === "Escape") {
        if (showStarPrompt) {
          setShowStarPrompt(false);
          return;
        }
        setIsFullSize(false);
      }
    };

    window.addEventListener("keydown", onKeyDown);

    return () => {
      window.removeEventListener("keydown", onKeyDown);
      document.body.style.overflow = originalOverflow;
    };
  }, [isFullSize, showStarPrompt]);

  const handleCopyRunCommand = (fileName) => {
    const command = `g++ ${dayFolder}/${fileName} -o ${fileName.split('.')[0]} && ./${fileName.split('.')[0]}`;
    navigator.clipboard.writeText(command).then(() => {
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    });
  };

  const handleNoteChange = (e) => {
    setNotes(e.target.value);
    localStorage.setItem(`notes-day${dayId}`, e.target.value);
  };

  const handleZoomIn = () => setZoomLevel((prev) => Math.min(prev + 10, 200));
  const handleZoomOut = () => setZoomLevel((prev) => Math.max(prev - 10, 70));
  const handleZoomReset = () => setZoomLevel(150);
  const selectedFileType = files[selectedFileIdx] ? getFileType(files[selectedFileIdx]) : "other";

  const handleDontShowAgain = () => {
    localStorage.setItem("hide-github-star-prompt", "true");
    setShowStarPrompt(false);
  };

  return (
    <div className="min-h-screen bg-gray-50 dark:bg-gray-900 pt-4 pb-8 px-2 md:px-8">
      {showStarPrompt && (
        <div className="fixed inset-0 z-[60] flex items-center justify-center bg-slate-900/70 p-4 backdrop-blur-sm">
          <div className="relative w-full max-w-xl overflow-hidden rounded-2xl border border-slate-200 bg-white shadow-2xl dark:border-slate-700 dark:bg-slate-900">
            <div className="absolute -left-10 -top-10 h-36 w-36 rounded-full bg-blue-400/20 blur-3xl dark:bg-blue-500/25" />
            <div className="absolute -right-14 bottom-0 h-36 w-36 rounded-full bg-cyan-400/20 blur-3xl dark:bg-cyan-500/20" />

            <button
              onClick={() => setShowStarPrompt(false)}
              className="absolute right-3 top-3 rounded-full p-2 text-slate-500 transition-colors hover:bg-slate-100 hover:text-slate-800 dark:text-slate-400 dark:hover:bg-slate-800 dark:hover:text-slate-100"
              aria-label="Close star prompt"
            >
              <FaTimes />
            </button>

            <div className="relative p-6 sm:p-8">
              <div className="mb-4 inline-flex items-center gap-2 rounded-full border border-yellow-300 bg-yellow-50 px-3 py-1 text-xs font-semibold text-yellow-700 dark:border-yellow-500/40 dark:bg-yellow-500/10 dark:text-yellow-300">
                <FaStar className="text-yellow-500" />
                Support the project
              </div>

              <h2 className="text-2xl font-bold text-slate-900 dark:text-white sm:text-3xl">
                Enjoying Day {dayNum}? Star us on GitHub
              </h2>
              <p className="mt-3 text-sm leading-relaxed text-slate-600 dark:text-slate-300 sm:text-base">
                If this folder helped you learn, a GitHub star motivates future updates and helps more learners discover this roadmap.
              </p>

              <div className="mt-6 flex flex-col gap-3 sm:flex-row">
                <a
                  href={githubRepoUrl}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="inline-flex items-center justify-center gap-2 rounded-xl bg-gradient-to-r from-blue-600 to-cyan-500 px-5 py-3 text-sm font-semibold text-white shadow-lg transition-transform hover:-translate-y-0.5 hover:from-blue-700 hover:to-cyan-600"
                >
                  <FaGithub className="text-base" />
                  Star us on GitHub
                </a>
                <button
                  onClick={handleDontShowAgain}
                  className="inline-flex items-center justify-center rounded-xl border border-slate-300 px-5 py-3 text-sm font-medium text-slate-700 transition-colors hover:bg-slate-100 dark:border-slate-600 dark:text-slate-300 dark:hover:bg-slate-800"
                >
                  Don&apos;t show again
                </button>
              </div>
            </div>
          </div>
        </div>
      )}

      {loading && <Loader />}
      <div className="max-w-7xl w-full mx-auto flex flex-col gap-6">
        {/* Header */}
        <div className="flex flex-col md:flex-row md:items-center md:justify-between gap-2 mb-2">
          <div>
            <h1 className="text-3xl md:text-4xl font-bold tracking-tight mb-1 text-gray-900 dark:text-white">Day {dayNum}</h1>
            <p className="text-lg text-gray-600 dark:text-gray-400 font-medium">C++ Challenge - Explore, Learn, Run & Note</p>
          </div>
          <div className="flex gap-2 mt-2 md:mt-0">
            {dayNum > 1 && (
              <Link to={`/day/${(dayNum - 1).toString().padStart(2, "0")}`} className="px-4 py-2 rounded-lg bg-white dark:bg-gray-800 text-gray-800 dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 transition font-medium shadow border border-gray-200 dark:border-gray-700">&larr; Prev</Link>
            )}
            {dayNum < 30 && (
              <Link to={`/day/${(dayNum + 1).toString().padStart(2, "0")}`} className="px-4 py-2 rounded-lg bg-white dark:bg-gray-800 text-gray-800 dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 transition font-medium shadow border border-gray-200 dark:border-gray-700">Next &rarr;</Link>
            )}
            <Link to="/" className="px-4 py-2 rounded-lg bg-blue-500 dark:bg-blue-600 text-white hover:bg-blue-600 dark:hover:bg-blue-700 transition font-medium shadow">Home</Link>
          </div>
        </div>

        {/* File Tabs */}
        <div className="flex gap-2 overflow-x-auto pb-2 custom-scrollbar">
          {files.map((file, idx) => (
            <button
              key={file}
              onClick={() => setSelectedFileIdx(idx)}
              className={`flex items-center gap-1 px-4 py-2 rounded-lg font-medium transition whitespace-nowrap
                          ${selectedFileIdx === idx 
                            ? 'bg-white dark:bg-gray-800 text-blue-600 dark:text-blue-400 shadow-md border border-blue-200 dark:border-blue-800' 
                            : 'bg-gray-100 dark:bg-gray-800/50 text-gray-700 dark:text-gray-300 hover:bg-gray-200 dark:hover:bg-gray-800 border border-transparent'}`}
            >
              {getFileIcon(file)}
              {file}
            </button>
          ))}
        </div>

        {/* Main Content Layout */}
        <div className={`flex flex-col gap-6 ${!isFullSize ? "lg:grid lg:grid-cols-[1fr_minmax(0,56rem)_20rem_1fr] lg:items-start" : ""}`}>
          {/* Main File Content */}
          <div className={`flex-1 w-full bg-white dark:bg-gray-800 rounded-xl shadow-lg p-6 border border-gray-200 dark:border-gray-700 ${!isFullSize ? "lg:col-start-2 lg:col-end-3" : ""} ${isFullSize ? "fixed inset-0 z-50 rounded-none border-0 p-4 md:p-6 overflow-y-auto" : ""}`}>
            <div className={`w-full mx-auto ${isFullSize ? "max-w-5xl" : "max-w-none"}`}>
            <div className="flex items-center justify-between mb-4">
              <span className="text-sm text-blue-600 dark:text-blue-400 font-mono">{files[selectedFileIdx] || 'No file selected.'}</span>
              <div className="flex items-center gap-2">
                {isFullSize && (
                  <>
                    <button
                      onClick={handleZoomOut}
                      className="p-2 rounded-lg bg-gray-100 dark:bg-gray-700 text-blue-600 dark:text-blue-400 hover:bg-gray-200 dark:hover:bg-gray-600 transition"
                      title="Zoom out"
                    >
                      <FaSearchMinus />
                    </button>
                    <button
                      onClick={handleZoomReset}
                      className="px-3 py-2 rounded-lg bg-gray-100 dark:bg-gray-700 text-blue-600 dark:text-blue-400 hover:bg-gray-200 dark:hover:bg-gray-600 transition text-xs font-semibold"
                      title="Reset zoom"
                    >
                      {zoomLevel}%
                    </button>
                    <button
                      onClick={handleZoomIn}
                      className="p-2 rounded-lg bg-gray-100 dark:bg-gray-700 text-blue-600 dark:text-blue-400 hover:bg-gray-200 dark:hover:bg-gray-600 transition"
                      title="Zoom in"
                    >
                      <FaSearchPlus />
                    </button>
                  </>
                )}
                <button
                  onClick={() => setIsFullSize((prev) => !prev)}
                  className="p-2 rounded-lg bg-gray-100 dark:bg-gray-700 text-blue-600 dark:text-blue-400 hover:bg-gray-200 dark:hover:bg-gray-600 transition"
                  title={isFullSize ? "Exit full size" : "Open full size"}
                >
                  {isFullSize ? <FaCompress /> : <FaExpand />}
                </button>
                {files[selectedFileIdx] && (
                  <a
                    href={`/${dayFolder}/${files[selectedFileIdx]}`}
                    download
                    className="p-2 rounded-lg bg-gray-100 dark:bg-gray-700 text-blue-600 dark:text-blue-400 hover:bg-gray-200 dark:hover:bg-gray-600 transition"
                    title="Download file"
                  >
                    <FaDownload />
                  </a>
                )}
              </div>
            </div>
            <div
              className={selectedFileType === "cpp" ? "max-w-none" : "prose prose-sm sm:prose lg:prose-lg dark:prose-invert max-w-none"}
              style={{ fontSize: `${isFullSize ? zoomLevel : 100}%` }}
            >
              {error ? (
                <div className="text-red-500 dark:text-red-400 font-semibold text-center py-8 bg-red-50 dark:bg-red-900/20 rounded-lg">{error}</div>
              ) : files[selectedFileIdx] ? (
                selectedFileType === "md" ? (
                  <div className="bg-gray-50 dark:bg-gray-900/50 rounded-lg p-6 text-left">
                    <ReactMarkdown>{fileContent}</ReactMarkdown>
                  </div>
                ) : selectedFileType === "cpp" ? (
                  <CodeBlock code={fileContent} language="cpp" fileName={files[selectedFileIdx]} />
                ) : selectedFileType === "txt" ? (
                  <pre className="whitespace-pre-wrap break-all bg-gray-50 dark:bg-gray-900/50 p-4 rounded-lg">{fileContent}</pre>
                ) : (
                  <pre className="whitespace-pre-wrap break-all text-gray-500 dark:text-gray-400 bg-gray-50 dark:bg-gray-900/50 p-4 rounded-lg">(Binary or unsupported file type)</pre>
                )
              ) : (
                 <div className="text-gray-500 dark:text-gray-400 text-center py-8">
                  {files.length === 0 ? "No files available for this day." : "Please select a file."}
                </div>
              )}
            </div>
            </div>
          </div>

          {/* Sidebar */}
          {!isFullSize && (
          <div className="w-full lg:w-80 lg:col-start-3 lg:col-end-4 flex-shrink-0 flex flex-col gap-6">
            {/* Files List */}
            <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-4 border border-gray-200 dark:border-gray-700">
              <h3 className="text-lg font-semibold text-gray-900 dark:text-white mb-3 flex items-center"><FaFileAlt className="mr-2 text-blue-500" />Files</h3>
              <ul className="space-y-2 max-h-64 overflow-y-auto custom-scrollbar">
                {files.map((file, idx) => (
                  <li 
                    key={file} 
                    className={`flex items-center gap-2 px-3 py-2 rounded-lg cursor-pointer transition
                                ${selectedFileIdx === idx 
                                  ? 'bg-blue-50 dark:bg-blue-900/20 text-blue-600 dark:text-blue-400' 
                                  : 'text-gray-700 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-700'}`} 
                    onClick={() => setSelectedFileIdx(idx)}
                  >
                    {getFileIcon(file)}
                    <span className="truncate text-sm">{file}</span>
                  </li>
                ))}
              </ul>
            </div>
            
            {/* Run & Learn */}
            <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-4 flex flex-col gap-3 border border-gray-200 dark:border-gray-700">
              <h3 className="text-lg font-semibold text-gray-900 dark:text-white mb-2 flex items-center"><FaTerminal className="mr-2 text-green-500" />Quick Actions</h3>
              {files[selectedFileIdx] && getFileType(files[selectedFileIdx]) === "cpp" && (
                <button
                  onClick={() => handleCopyRunCommand(files[selectedFileIdx])}
                  className={`w-full flex items-center justify-center gap-2 px-4 py-2 rounded-lg bg-blue-500 text-white font-medium hover:bg-blue-600 transition ${copied ? 'opacity-70' : ''}`}
                >
                  {copied ? 'Copied!' : 'Copy Run Command'}
                </button>
              )}
              <a
                href="https://www.onlinegdb.com/online_c++_compiler"
                target="_blank"
                rel="noopener noreferrer"
                className="w-full flex items-center justify-center gap-2 px-4 py-2 rounded-lg bg-purple-500 text-white font-medium hover:bg-purple-600 transition"
              >
                Run Online <FaTerminal />
              </a>
            </div>
            
            {/* Notes */}
            <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-4 flex flex-col gap-2 border border-gray-200 dark:border-gray-700">
              <h3 className="text-lg font-semibold text-gray-900 dark:text-white mb-2 flex items-center"><FaRegStickyNote className="mr-2 text-yellow-500" />Notes</h3>
              <textarea
                className="w-full min-h-[100px] rounded-lg bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-white p-3 resize-vertical focus:outline-none focus:ring-2 focus:ring-blue-500 border border-gray-200 dark:border-gray-700"
                placeholder="Write your notes here..."
                value={notes}
                onChange={handleNoteChange}
              />
              <button
                onClick={() => setNotes("")}
                className="self-end text-xs text-blue-500 dark:text-blue-400 hover:underline"
              >
                Clear Notes
              </button>
            </div>
          </div>
          )}
        </div>
      </div>
    </div>
  );
};

export default Day;

// 30 Days of C++ - By bhanu partap - learn more about me at https://github.com/Bhanu-partap-13