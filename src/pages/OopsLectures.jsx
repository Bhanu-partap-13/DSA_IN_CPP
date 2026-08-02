import React from "react";
import { Link } from "react-router-dom";
import { motion } from "framer-motion";
import { FiBookOpen } from "react-icons/fi";
import contentIndex from "../data/contentIndex.json";

const OopsLectures = () => {
  const lectures = Object.keys(contentIndex?.oops || {}).sort((a, b) =>
    a.localeCompare(b, "en", { numeric: true, sensitivity: "base" })
  );

  return (
    <div className="min-h-screen bg-gray-50 dark:bg-gray-900 py-8">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <motion.div
          initial={{ opacity: 0, y: -20 }}
          animate={{ opacity: 1, y: 0 }}
          className="mb-8 text-center"
        >
          <div className="inline-flex items-center justify-center w-16 h-16 rounded-full bg-gradient-to-br from-emerald-500 to-cyan-600 text-white text-2xl mb-4">
            <FiBookOpen />
          </div>
          <h1 className="text-3xl md:text-4xl font-bold text-gray-900 dark:text-white mb-2">
            OOPS Lectures
          </h1>
          <p className="text-gray-600 dark:text-gray-400">
            {lectures.length} {lectures.length === 1 ? "lecture" : "lectures"} available
          </p>
        </motion.div>

        {lectures.length === 0 ? (
          <div className="text-center py-20 text-gray-500 dark:text-gray-400 text-lg">
            No OOPS lectures available yet.
          </div>
        ) : (
          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6">
            {lectures.map((lecture, index) => {
              const fileCount = contentIndex.oops[lecture]?.length || 0;
              return (
                <motion.div
                  key={lecture}
                  initial={{ opacity: 0, y: 20 }}
                  animate={{ opacity: 1, y: 0 }}
                  transition={{ delay: index * 0.05 }}
                >
                  <Link to={`/oops/${lecture}`} className="block group">
                    <div className="bg-white dark:bg-gray-800 rounded-xl p-6 shadow-lg border border-gray-200 dark:border-gray-700 hover:shadow-2xl transition-all duration-300 hover:-translate-y-1">
                      <h2 className="text-xl font-bold text-gray-900 dark:text-white mb-2 group-hover:text-cyan-600 dark:group-hover:text-cyan-400">
                        {lecture}
                      </h2>
                      <p className="text-sm text-gray-600 dark:text-gray-400">
                        {fileCount} {fileCount === 1 ? "file" : "files"}
                      </p>
                    </div>
                  </Link>
                </motion.div>
              );
            })}
          </div>
        )}
      </div>
    </div>
  );
};

export default OopsLectures;
