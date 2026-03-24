import React, { useState } from 'react';
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { vscDarkPlus } from 'react-syntax-highlighter/dist/esm/styles/prism';
import { atomOneLight } from 'react-syntax-highlighter/dist/esm/styles/hljs';
import { FiCopy, FiCheck } from 'react-icons/fi';
import toast from 'react-hot-toast';
import { useTheme } from '../contexts/ThemeContext';

const CodeBlock = ({ code, language = 'cpp', fileName = '' }) => {
  const [copied, setCopied] = useState(false);
  const { theme } = useTheme();

  const handleCopy = async () => {
    try {
      await navigator.clipboard.writeText(code);
      setCopied(true);
      toast.success('Code copied to clipboard!', {
        duration: 2000,
        position: 'top-center',
        style: {
          background: theme === 'dark' ? '#1f2937' : '#fff',
          color: theme === 'dark' ? '#fff' : '#000',
        },
      });
      setTimeout(() => setCopied(false), 2000);
    } catch (err) {
      toast.error('Failed to copy code');
    }
  };

  return (
    <div className="relative group my-4 w-full rounded-xl overflow-hidden border border-gray-200 dark:border-gray-700/50 shadow-lg">
      {fileName && (
        <div className="bg-gray-100 dark:bg-gray-800/50 px-4 py-2 text-sm font-mono text-gray-700 dark:text-gray-300 border-b border-gray-200 dark:border-gray-700/50">
          {fileName}
        </div>
      )}
      <div className="relative">
        <button
          onClick={handleCopy}
          className="absolute top-3 right-3 p-2 rounded-lg bg-gray-100 dark:bg-gray-800 hover:bg-gray-200 dark:hover:bg-gray-700 transition-all duration-200 opacity-0 group-hover:opacity-100 z-10"
          title="Copy code"
        >
          {copied ? (
            <FiCheck className="w-4 h-4 text-green-500" />
          ) : (
            <FiCopy className="w-4 h-4 text-gray-600 dark:text-gray-300" />
          )}
        </button>
        <SyntaxHighlighter
          language={language}
          style={theme === 'dark' ? vscDarkPlus : atomOneLight}
          customStyle={{
            margin: 0,
            padding: '1.5rem',
            background: theme === 'dark' ? '#1f2937' : '#f9fafb',
            fontSize: '0.875rem',
            lineHeight: '1.5',
            width: '100%',
            overflowX: 'auto',
          }}
          showLineNumbers
          wrapLines
        >
          {code}
        </SyntaxHighlighter>
      </div>
    </div>
  );
};

export default CodeBlock;
