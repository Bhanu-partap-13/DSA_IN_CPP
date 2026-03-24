import React, { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import { motion } from 'framer-motion';
import { FiArrowLeft, FiFileText } from 'react-icons/fi';
import CodeBlock from '../components/CodeBlock';
import Loader from '../components/Loader';
import contentIndex from '../data/contentIndex.json';

const Topics = () => {
  const { topicName } = useParams();
  const [files, setFiles] = useState([]);
  const [selectedFile, setSelectedFile] = useState(null);
  const [fileContent, setFileContent] = useState('');
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    loadFiles();
  }, [topicName]);

  useEffect(() => {
    if (selectedFile) {
      loadFileContent(selectedFile);
    }
  }, [selectedFile, topicName]);

  const loadFiles = () => {
    setLoading(true);
    const topicFiles = (contentIndex?.topics?.[topicName] || []).filter((fileName) => fileName.toLowerCase().endsWith('.cpp'));
    setFiles(topicFiles);
    if (topicFiles.length > 0) {
      setSelectedFile(topicFiles[0]);
    }
    setLoading(false);
  };

  const loadFileContent = async (fileName) => {
    if (!fileName) return;
    
    try {
      setLoading(true);
      const response = await fetch(`/Topics/${topicName}/${fileName}?t=${Date.now()}`, {
        cache: 'no-store',
      });
      if (!response.ok) {
        throw new Error(`HTTP error! status: ${response.status}`);
      }
      const content = await response.text();
      setFileContent(content);
    } catch (error) {
      console.error('Error loading file content:', error);
      setFileContent(`// Error loading file: ${fileName}\n// Please check if the file exists at /Topics/${topicName}/${fileName}`);
    } finally {
      setLoading(false);
    }
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
          className="mb-8"
        >
          <Link
            to="/all-topics"
            className="inline-flex items-center text-blue-600 dark:text-blue-400 hover:text-blue-700 dark:hover:text-blue-300 mb-4"
          >
            <FiArrowLeft className="mr-2" />
            Back to Topics
          </Link>
          <h1 className="text-3xl md:text-4xl font-bold text-gray-900 dark:text-white">
            {topicName}
          </h1>
          <p className="text-gray-600 dark:text-gray-400 mt-2">
            {files.length} {files.length === 1 ? 'file' : 'files'} available
          </p>
        </motion.div>

        <div className="grid grid-cols-1 lg:grid-cols-4 gap-6">
          {/* File List Sidebar */}
          <motion.div
            initial={{ opacity: 0, x: -20 }}
            animate={{ opacity: 1, x: 0 }}
            className="lg:col-span-1"
          >
            <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-4 sticky top-20">
              <h2 className="text-lg font-semibold text-gray-900 dark:text-white mb-4">
                Files
              </h2>
              <div className="space-y-2 max-h-[calc(100vh-200px)] overflow-y-auto">
                {files.map((file) => (
                  <button
                    key={file}
                    onClick={() => setSelectedFile(file)}
                    className={`w-full text-left px-3 py-2 rounded-lg text-sm transition-colors flex items-center ${
                      selectedFile === file
                        ? 'bg-blue-50 dark:bg-blue-900/30 text-blue-600 dark:text-blue-400 font-medium'
                        : 'text-gray-700 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-700'
                    }`}
                  >
                    <FiFileText className="mr-2 flex-shrink-0" />
                    <span className="truncate">{file}</span>
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
            <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-6 border border-gray-200 dark:border-gray-700">
              {files.length === 0 ? (
                <div className="text-center py-12">
                  <p className="text-gray-500 dark:text-gray-400 text-lg mb-2">
                    No files available for this topic yet.
                  </p>
                  <p className="text-gray-400 dark:text-gray-500 text-sm">
                    Coming soon!
                  </p>
                </div>
              ) : (
                <>
                  <h2 className="text-xl font-semibold text-gray-900 dark:text-white mb-4">
                    {selectedFile}
                  </h2>
                  {loading ? (
                    <div className="text-center py-12">
                      <Loader />
                    </div>
                  ) : fileContent ? (
                    <CodeBlock code={fileContent} language="cpp" fileName={selectedFile} />
                  ) : (
                    <div className="text-center py-12 text-gray-500 dark:text-gray-400">
                      Select a file to view its content
                    </div>
                  )}
                </>
              )}
            </div>
          </motion.div>
        </div>
      </div>
    </div>
  );
};

export default Topics;
