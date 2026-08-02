import React, { useRef } from "react";
import { Link } from "react-router-dom";
import { motion } from "framer-motion";
import { 
  FaCode, 
  FaRocket, 
  FaLightbulb, 
  FaLayerGroup, 
  FaLaptopCode,
  FaBookOpen,
  FaChartLine,
  FaProjectDiagram,
  FaNetworkWired
} from "react-icons/fa";
import { HiCode, HiSparkles } from "react-icons/hi";
import daysFiles from "../data/daysFiles.json";
import AnimatedCodeDisplay from "../components/AnimatedCodeDisplay";
import { DayCard, GlobalSpotlight } from "../components/DayCard";

const days = Array.from({ length: 30 }, (_, i) => i + 1);

const Home = () => {
  const curriculumRef = useRef(null);
  
  const features = [
    {
      icon: <FaCode />,
      title: "30 Days Journey",
      description: "Structured daily lessons from basics to advanced topics",
      color: "from-blue-500 to-cyan-500"
    },
    {
      icon: <FaLightbulb />,
      title: "Practical Examples",
      description: "Real-world code examples you can run and experiment with",
      color: "from-purple-500 to-pink-500"
    },
    {
      icon: <FaChartLine />,
      title: "Progressive Learning",
      description: "Build your skills step by step with increasing complexity",
      color: "from-green-500 to-teal-500"
    }
  ];

  const sections = [
    {
      path: "/all-topics",
      title: "DSA Topics",
      description: "Arrays, Sorting, Searching & More",
      icon: <FaLayerGroup />,
      count: "15+ Problems",
      color: "from-blue-500 to-cyan-500",
      bgColor: "bg-blue-50 dark:bg-blue-900/20",
      textColor: "text-blue-600 dark:text-blue-400"
    },
    {
      path: "/leetcode",
      title: "LeetCode",
      description: "Optimized solutions to top problems",
      icon: <FaLaptopCode />,
      count: "7 Solutions",
      color: "from-orange-500 to-red-500",
      bgColor: "bg-orange-50 dark:bg-orange-900/20",
      textColor: "text-orange-600 dark:text-orange-400"
    },
    {
      path: "/problems",
      title: "Problems",
      description: "Curated competitive programming",
      icon: <FaBookOpen />,
      count: "Growing Collection",
      color: "from-purple-500 to-pink-500",
      bgColor: "bg-purple-50 dark:bg-purple-900/20",
      textColor: "text-purple-600 dark:text-purple-400"
    },
    {
      path: "/codeforces",
      title: "Codeforces",
      description: "Contest problems and solutions",
      icon: <FaProjectDiagram />,
      count: "11 Solutions",
      color: "from-indigo-500 to-blue-500",
      bgColor: "bg-indigo-50 dark:bg-indigo-900/20",
      textColor: "text-indigo-600 dark:text-indigo-400"
    },
    {
      path: "/oops",
      title: "OOPS",
      description: "Lecture-wise object-oriented programming",
      icon: <FaNetworkWired />,
      count: "7 Lectures",
      color: "from-emerald-500 to-cyan-500",
      bgColor: "bg-emerald-50 dark:bg-emerald-900/20",
      textColor: "text-emerald-600 dark:text-emerald-400"
    }
  ];

  const containerVariants = {
    hidden: { opacity: 0 },
    visible: {
      opacity: 1,
      transition: {
        staggerChildren: 0.1
      }
    }
  };

  const itemVariants = {
    hidden: { y: 20, opacity: 0 },
    visible: {
      y: 0,
      opacity: 1,
      transition: {
        duration: 0.5
      }
    }
  };

  return (
    <div className="min-h-screen bg-gray-50 dark:bg-gray-900">
      {/* Hero Section */}
      <section className="relative overflow-hidden bg-gradient-to-br from-blue-50 via-white to-purple-50 dark:from-gray-900 dark:via-gray-900 dark:to-gray-900 border-b border-gray-200 dark:border-gray-800">
        <div className="absolute inset-0 bg-grid-pattern opacity-5"></div>
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-20 md:py-32 relative">
          <div className="grid grid-cols-1 lg:grid-cols-2 gap-12 items-center">
            {/* Left side - Text content */}
            <motion.div
              initial={{ opacity: 0, x: -20 }}
              animate={{ opacity: 1, x: 0 }}
              transition={{ duration: 0.8 }}
            >
              <motion.div
                initial={{ scale: 0 }}
                animate={{ scale: 1 }}
                transition={{ delay: 0.2, type: "spring", stiffness: 200 }}
                className="inline-flex items-center gap-2 px-4 py-2 bg-blue-100 dark:bg-blue-900/30 rounded-full text-blue-600 dark:text-blue-400 text-sm font-medium mb-6"
              >
                <HiSparkles className="text-lg" />
                Master C++ in 30 Days
              </motion.div>
              
              <h1 className="text-4xl sm:text-5xl md:text-6xl font-bold text-gray-900 dark:text-white mb-6 leading-tight">
                Learn C++ from
                <span className="block bg-gradient-to-r from-blue-600 via-purple-600 to-pink-600 dark:from-blue-400 dark:via-purple-400 dark:to-pink-400 text-transparent bg-clip-text mt-2">
                  Zero to Hero
                </span>
              </h1>
              
              <p className="text-lg md:text-xl text-gray-600 dark:text-gray-400 mb-10">
                Your accelerated journey to mastering C++. Dive into daily challenges, 
                explore real code, and build your expertise from the ground up.
              </p>
              
              <div className="flex flex-col sm:flex-row gap-4">
                <Link to="/day/01">
                  <motion.button
                    whileHover={{ scale: 1.05 }}
                    whileTap={{ scale: 0.95 }}
                    className="px-8 py-4 bg-gradient-to-r from-blue-600 to-purple-600 text-white font-semibold rounded-xl shadow-lg hover:shadow-xl transition-all flex items-center gap-2"
                  >
                    <FaRocket />
                    Start Learning
                  </motion.button>
                </Link>
                <button
                  onClick={() => document.getElementById('explore-section')?.scrollIntoView({ behavior: 'smooth' })}
                  className="px-8 py-4 bg-white dark:bg-gray-800 text-gray-900 dark:text-white font-semibold rounded-xl shadow-lg hover:shadow-xl transition-all border border-gray-200 dark:border-gray-700"
                >
                  Explore Sections
                </button>
              </div>
            </motion.div>

            {/* Right side - Animated Code Display */}
            <motion.div
              initial={{ opacity: 0, x: 20 }}
              animate={{ opacity: 1, x: 0 }}
              transition={{ duration: 0.8, delay: 0.2 }}
              className="hidden lg:block"
            >
              <AnimatedCodeDisplay />
            </motion.div>
          </div>
        </div>
      </section>

      {/* Features Section */}
      <section className="py-16 md:py-24 px-4 sm:px-6 lg:px-8">
        <div className="max-w-7xl mx-auto">
          <motion.div
            initial={{ opacity: 0, y: 20 }}
            whileInView={{ opacity: 1, y: 0 }}
            viewport={{ once: true }}
            transition={{ duration: 0.6 }}
            className="text-center mb-12"
          >
            <h2 className="text-3xl md:text-4xl font-bold text-gray-900 dark:text-white mb-4">
              Why Choose This Course?
            </h2>
            <p className="text-gray-600 dark:text-gray-400 text-lg max-w-2xl mx-auto">
              Everything you need to master C++ programming in one place
            </p>
          </motion.div>

          <div className="grid grid-cols-1 md:grid-cols-2 xl:grid-cols-3 gap-8">
            {features.map((feature, index) => (
              <motion.div
                key={index}
                initial={{ opacity: 0, y: 20 }}
                whileInView={{ opacity: 1, y: 0 }}
                viewport={{ once: true }}
                transition={{ delay: index * 0.1 }}
                className="group relative bg-white dark:bg-gray-800 rounded-xl p-8 shadow-lg hover:shadow-2xl transition-all duration-300 border border-gray-200 dark:border-gray-700 overflow-hidden"
              >
                <div className={`absolute top-0 right-0 w-32 h-32 bg-gradient-to-br ${feature.color} opacity-10 rounded-full -mr-16 -mt-16 group-hover:scale-150 transition-transform duration-500`}></div>
                
                <div className="relative">
                  <div className={`w-14 h-14 rounded-xl bg-gradient-to-br ${feature.color} flex items-center justify-center text-white text-2xl mb-6 group-hover:scale-110 transition-transform`}>
                    {feature.icon}
                  </div>
                  <h3 className="text-xl font-bold text-gray-900 dark:text-white mb-3">
                    {feature.title}
                  </h3>
                  <p className="text-gray-600 dark:text-gray-400">
                    {feature.description}
                  </p>
                </div>
              </motion.div>
            ))}
          </div>
        </div>
      </section>

      {/* Sections Grid */}
      <section id="explore-section" className="py-16 md:py-24 px-4 sm:px-6 lg:px-8 bg-white dark:bg-gray-800/50">
        <div className="max-w-7xl mx-auto">
          <motion.div
            initial={{ opacity: 0, y: 20 }}
            whileInView={{ opacity: 1, y: 0 }}
            viewport={{ once: true }}
            className="text-center mb-12"
          >
            <h2 className="text-3xl md:text-4xl font-bold text-gray-900 dark:text-white mb-4">
              Explore Different Sections
            </h2>
            <p className="text-gray-600 dark:text-gray-400 text-lg">
              Practice with DSA topics, LeetCode problems, and more
            </p>
          </motion.div>

          <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
            {sections.map((section, index) => (
              <Link key={index} to={section.path}>
                <motion.div
                  initial={{ opacity: 0, scale: 0.9 }}
                  whileInView={{ opacity: 1, scale: 1 }}
                  viewport={{ once: true }}
                  transition={{ delay: index * 0.1 }}
                  whileHover={{ y: -8, scale: 1.02 }}
                  className={`${section.bgColor} rounded-2xl p-8 shadow-lg hover:shadow-2xl transition-all duration-300 border border-gray-200 dark:border-gray-700 group cursor-pointer`}
                >
                  <div className={`w-16 h-16 rounded-xl bg-gradient-to-br ${section.color} flex items-center justify-center text-white text-3xl mb-6 group-hover:scale-110 transition-transform`}>
                    {section.icon}
                  </div>
                  <h3 className={`text-2xl font-bold ${section.textColor} mb-3`}>
                    {section.title}
                  </h3>
                  <p className="text-gray-700 dark:text-gray-300 mb-4">
                    {section.description}
                  </p>
                  <div className={`text-sm font-semibold ${section.textColor} flex items-center justify-between`}>
                    <span>{section.count}</span>
                    <span className="transform group-hover:translate-x-2 transition-transform">→</span>
                  </div>
                </motion.div>
              </Link>
            ))}
          </div>
        </div>
      </section>

      {/* 30 Days Grid */}
      <section className="py-16 md:py-24 px-4 sm:px-6 lg:px-8 relative" ref={curriculumRef}>
        <GlobalSpotlight containerRef={curriculumRef} />
        
        <div className="max-w-7xl mx-auto">
          <motion.div
            initial={{ opacity: 0, y: 20 }}
            whileInView={{ opacity: 1, y: 0 }}
            viewport={{ once: true }}
            className="text-center mb-12"
          >
            <h2 className="text-3xl md:text-4xl font-bold text-gray-900 dark:text-white mb-4">
              30 Days Curriculum
            </h2>
            <p className="text-gray-600 dark:text-gray-400 text-lg">
              Hover over any day to see the magic ✨
            </p>
          </motion.div>

          <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-6">
            {days.map((day, index) => {
              const dayFolder = `Day${day.toString().padStart(2, "0")}`;
              const hasContent = daysFiles[dayFolder]?.length > 0;
              
              return (
                <DayCard 
                  key={day} 
                  day={day} 
                  hasContent={hasContent}
                  index={index}
                />
              );
            })}
          </div>
        </div>
      </section>

      {/* CTA Section */}
      <section className="py-16 md:py-24 px-4 sm:px-6 lg:px-8 bg-gradient-to-br from-blue-600 to-purple-600 dark:from-blue-700 dark:to-purple-700">
        <div className="max-w-4xl mx-auto text-center">
          <motion.div
            initial={{ opacity: 0, y: 20 }}
            whileInView={{ opacity: 1, y: 0 }}
            viewport={{ once: true }}
          >
            <HiCode className="text-6xl text-white mx-auto mb-6" />
            <h2 className="text-3xl md:text-4xl font-bold text-white mb-6">
              Ready to Start Your Journey?
            </h2>
            <p className="text-xl text-blue-100 mb-8">
              Join thousands of developers mastering C++ one day at a time
            </p>
            <Link to="/day/01">
              <motion.button
                whileHover={{ scale: 1.05 }}
                whileTap={{ scale: 0.95 }}
                className="px-10 py-4 bg-white text-blue-600 font-bold rounded-xl shadow-2xl hover:shadow-3xl transition-all text-lg"
              >
                Begin Day 1 Now
              </motion.button>
            </Link>
          </motion.div>
        </div>
      </section>
    </div>
  );
};

export default Home;

