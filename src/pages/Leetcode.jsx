import React, { useState, useEffect } from 'react';
import { motion } from 'framer-motion';
import { FiCode, FiExternalLink, FiAward } from 'react-icons/fi';
import CodeBlock from '../components/CodeBlock';
import Loader from '../components/Loader';
import contentIndex from '../data/contentIndex.json';

const Leetcode = () => {
  const [problems, setProblems] = useState([]);
  const [selectedProblem, setSelectedProblem] = useState(null);
  const [fileContent, setFileContent] = useState('');
  const [loading, setLoading] = useState(true);

  const knownMetadata = {
    33: {
      title: 'Search in Rotated Sorted Array',
      difficulty: 'Medium',
      slug: 'search-in-rotated-sorted-array',
    },
    74: {
      title: 'Search a 2D Matrix',
      difficulty: 'Medium',
      slug: 'search-a-2d-matrix',
    },
    153: {
      title: 'Find Minimum in Rotated Sorted Array',
      difficulty: 'Medium',
      slug: 'find-minimum-in-rotated-sorted-array',
    },
    239: {
      title: 'Sliding Window Maximum',
      difficulty: 'Hard',
      slug: 'sliding-window-maximum',
    },
    643: {
      title: 'Maximum Average Subarray I',
      difficulty: 'Easy',
      slug: 'maximum-average-subarray-i',
    },
    680: {
      title: 'Valid Palindrome II',
      difficulty: 'Easy',
      slug: 'valid-palindrome-ii',
    },
    1760: {
      title: 'Minimum Limit of Balls in a Bag',
      difficulty: 'Medium',
      slug: 'minimum-limit-of-balls-in-a-bag',
    },
  };

  useEffect(() => {
    const indexedProblems = (contentIndex?.leetcode || [])
      .filter((fileName) => fileName.toLowerCase().endsWith('.cpp'))
      .map((fileName) => {
        const number = fileName.replace(/\.cpp$/i, '');
        const metadata = knownMetadata[number] || {};

        return {
          number,
          title: metadata.title || `Problem ${number}`,
          difficulty: metadata.difficulty || 'Medium',
          slug: metadata.slug || '',
          file: fileName,
        };
      })
      .sort((a, b) => Number(a.number) - Number(b.number));

    setProblems(indexedProblems);
    if (indexedProblems.length > 0) {
      setSelectedProblem(indexedProblems[0]);
    }
    setLoading(false);
  }, []);

  useEffect(() => {
    if (selectedProblem) {
      loadFileContent(selectedProblem.file);
    }
  }, [selectedProblem]);

  const loadFileContent = async (fileName) => {
    try {
      const response = await fetch(`/Leetcode/${fileName}?t=${Date.now()}`, {
        cache: 'no-store',
      });
      const content = await response.text();
      setFileContent(content);
    } catch (error) {
      console.error('Error loading file content:', error);
      setFileContent('// Error loading file content');
    }
  };

  const getDifficultyColor = (difficulty) => {
    switch (difficulty.toLowerCase()) {
      case 'easy':
        return 'bg-green-100 dark:bg-green-900/30 text-green-600 dark:text-green-400 border-green-200 dark:border-green-800';
      case 'medium':
        return 'bg-yellow-100 dark:bg-yellow-900/30 text-yellow-600 dark:text-yellow-400 border-yellow-200 dark:border-yellow-800';
      case 'hard':
        return 'bg-red-100 dark:bg-red-900/30 text-red-600 dark:text-red-400 border-red-200 dark:border-red-800';
      default:
        return 'bg-gray-100 dark:bg-gray-700 text-gray-600 dark:text-gray-400';
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
          className="mb-8 text-center"
        >
          <div className="inline-flex items-center justify-center w-16 h-16 rounded-full bg-gradient-to-br from-orange-500 to-red-500 text-white text-2xl mb-4">
            <FiCode />
          </div>
          <h1 className="text-3xl md:text-4xl font-bold text-gray-900 dark:text-white mb-2">
            LeetCode Solutions
          </h1>
          <p className="text-gray-600 dark:text-gray-400">
            {problems.length} problems solved in C++
          </p>
        </motion.div>

        <div className="grid grid-cols-1 lg:grid-cols-4 gap-6">
          {/* Problem List */}
          <motion.div
            initial={{ opacity: 0, x: -20 }}
            animate={{ opacity: 1, x: 0 }}
            className="lg:col-span-1"
          >
            <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-4 sticky top-20 border border-gray-200 dark:border-gray-700">
              <h2 className="text-lg font-semibold text-gray-900 dark:text-white mb-4 flex items-center gap-2">
                <FiAward className="text-orange-500" />
                Problems
              </h2>
              <div className="space-y-2 max-h-[calc(100vh-200px)] overflow-y-auto custom-scrollbar">
                {problems.map((problem) => (
                  <button
                    key={problem.number}
                    onClick={() => setSelectedProblem(problem)}
                    className={`w-full text-left px-3 py-3 rounded-lg text-sm transition-all duration-200 border ${
                      selectedProblem?.number === problem.number
                        ? 'bg-orange-50 dark:bg-orange-900/20 text-orange-600 dark:text-orange-400 font-medium border-orange-200 dark:border-orange-800 shadow-md'
                        : 'text-gray-700 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-700 border-transparent'
                    }`}
                  >
                    <div className="flex items-center justify-between mb-1">
                      <span className="font-mono font-semibold">#{problem.number}</span>
                      <span className={`text-xs px-2 py-0.5 rounded-full border ${getDifficultyColor(problem.difficulty)}`}>
                        {problem.difficulty}
                      </span>
                    </div>
                    <div className="text-xs text-gray-600 dark:text-gray-400 line-clamp-2">
                      {problem.title}
                    </div>
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
              {/* Problem Header */}
              <div className="mb-6">
                <div className="flex items-start justify-between mb-3">
                  <div className="flex-1">
                    <div className="flex items-center gap-3 mb-2">
                      <h2 className="text-2xl font-bold text-gray-900 dark:text-white">
                        #{selectedProblem?.number}. {selectedProblem?.title}
                      </h2>
                    </div>
                    <span className={`inline-block text-xs px-3 py-1 rounded-full border font-semibold ${getDifficultyColor(selectedProblem?.difficulty)}`}>
                      {selectedProblem?.difficulty}
                    </span>
                  </div>
                </div>
                
                {/* Animated View on LeetCode Button */}
                <motion.a
                  href={selectedProblem?.slug ? `https://leetcode.com/problems/${selectedProblem.slug}/` : `https://leetcode.com/problemset/all/?search=${selectedProblem?.number || ''}`}
                  target="_blank"
                  rel="noopener noreferrer"
                  whileHover={{ scale: 1.02, y: -2 }}
                  whileTap={{ scale: 0.98 }}
                  className="inline-flex items-center gap-2 px-6 py-3 bg-gradient-to-r from-orange-500 to-red-500 hover:from-orange-600 hover:to-red-600 text-white font-semibold rounded-lg shadow-lg hover:shadow-xl transition-all duration-300 group"
                >
                  <FiExternalLink className="group-hover:rotate-12 transition-transform duration-300" />
                  View on LeetCode
                  <motion.span
                    animate={{ x: [0, 4, 0] }}
                    transition={{ repeat: Infinity, duration: 1.5 }}
                  >
                    →
                  </motion.span>
                </motion.a>
              </div>

              {/* Code Block */}
              {fileContent ? (
                <div className="relative">
                  <CodeBlock code={fileContent} language="cpp" fileName={selectedProblem?.file} />
                </div>
              ) : (
                <div className="text-center py-12 text-gray-500 dark:text-gray-400">
                  Select a problem to view its solution
                </div>
              )}
            </div>
          </motion.div>
        </div>
      </div>
    </div>
  );
};

export default Leetcode;
