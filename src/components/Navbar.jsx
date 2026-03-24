import React, { useState } from "react";
import { Link, useLocation } from "react-router-dom";
import { FaGithub, FaSun, FaMoon, FaCode, FaStar } from "react-icons/fa";
import { HiMenuAlt3, HiX } from "react-icons/hi";
import { useTheme } from "../contexts/ThemeContext";

const Navbar = () => {
  const { theme, toggleTheme } = useTheme();
  const [isMenuOpen, setIsMenuOpen] = useState(false);
  const location = useLocation();

  const navLinks = [
    { path: "/", label: "Home" },
    { path: "/all-topics", label: "Topics" },
    { path: "/leetcode", label: "LeetCode" },
    { path: "/problems", label: "Problems" },
  ];

  const isActive = (path) => location.pathname === path;

  return (
    <nav className="fixed top-0 left-0 right-0 z-50 bg-white/70 dark:bg-gray-900/70 backdrop-blur-xl border-b border-gray-200/50 dark:border-gray-800/50">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="flex items-center justify-between h-16">
          {/* Logo */}
          <Link 
            to="/" 
            className="flex items-center space-x-2 group"
          >
            <div className="w-9 h-9 rounded-lg bg-gradient-to-br from-blue-500 to-purple-600 flex items-center justify-center transform group-hover:scale-110 transition-transform duration-200">
              <FaCode className="text-white text-lg" />
            </div>
            <span className="text-lg font-semibold text-gray-900 dark:text-white hidden sm:block">
              30 Days of C++
            </span>
          </Link>

          {/* Desktop Navigation */}
          <div className="hidden md:flex items-center space-x-1">
            {navLinks.map((link) => (
              <Link
                key={link.path}
                to={link.path}
                className={`px-4 py-2 rounded-lg text-sm font-medium transition-all duration-200 ${
                  isActive(link.path)
                    ? "bg-blue-50 dark:bg-blue-900/30 text-blue-600 dark:text-blue-400"
                    : "text-gray-600 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-800"
                }`}
              >
                {link.label}
              </Link>
            ))}
            
            <div className="ml-4 flex items-center space-x-2">
              <a
                href="https://github.com/Bhanu-partap-13/30-Days-Of-CPP"
                target="_blank"
                rel="noopener noreferrer"
                className="group relative inline-flex items-center gap-2 rounded-xl border border-gray-200 bg-white px-3 py-2 text-sm font-semibold text-gray-700 shadow-sm transition-all duration-200 hover:-translate-y-0.5 hover:border-amber-300 hover:bg-amber-50 hover:text-amber-700 hover:shadow dark:border-gray-700 dark:bg-gray-900 dark:text-gray-200 dark:hover:border-amber-400/60 dark:hover:bg-amber-500/10 dark:hover:text-amber-300"
                aria-label="Star us on GitHub"
                title="Star us on GitHub"
              >
                <span className="relative inline-flex items-center justify-center">
                  <FaGithub className="h-5 w-5" />
                  <FaStar className="absolute -right-2 -top-2 h-3 w-3 text-amber-400 transition-transform group-hover:scale-110" />
                </span>
                <span className="hidden lg:inline">Star us on GitHub</span>
              </a>
              <button
                onClick={toggleTheme}
                className="p-2 rounded-lg text-gray-600 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-800 transition-colors"
                aria-label="Toggle theme"
              >
                {theme === 'dark' ? <FaSun className="w-5 h-5" /> : <FaMoon className="w-5 h-5" />}
              </button>
            </div>
          </div>

          {/* Mobile menu button */}
          <div className="md:hidden flex items-center space-x-2">
            <button
              onClick={toggleTheme}
              className="p-2 rounded-lg text-gray-600 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-800"
              aria-label="Toggle theme"
            >
              {theme === 'dark' ? <FaSun className="w-5 h-5" /> : <FaMoon className="w-5 h-5" />}
            </button>
            <button
              onClick={() => setIsMenuOpen(!isMenuOpen)}
              className="p-2 rounded-lg text-gray-600 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-800"
              aria-label="Toggle menu"
            >
              {isMenuOpen ? <HiX className="w-6 h-6" /> : <HiMenuAlt3 className="w-6 h-6" />}
            </button>
          </div>
        </div>

        {/* Mobile Navigation */}
        {isMenuOpen && (
          <div className="md:hidden py-4 space-y-2 border-t border-gray-200 dark:border-gray-800">
            {navLinks.map((link) => (
              <Link
                key={link.path}
                to={link.path}
                onClick={() => setIsMenuOpen(false)}
                className={`block px-4 py-2 rounded-lg text-sm font-medium transition-colors ${
                  isActive(link.path)
                    ? "bg-blue-50 dark:bg-blue-900/30 text-blue-600 dark:text-blue-400"
                    : "text-gray-600 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-800"
                }`}
              >
                {link.label}
              </Link>
            ))}
            <a
              href="https://github.com/Bhanu-partap-13/30-Days-Of-CPP"
              target="_blank"
              rel="noopener noreferrer"
              className="group mt-2 flex items-center justify-between rounded-xl border border-amber-200 bg-amber-50 px-4 py-3 text-sm font-semibold text-amber-700 transition-colors hover:bg-amber-100 dark:border-amber-500/40 dark:bg-amber-500/10 dark:text-amber-300 dark:hover:bg-amber-500/20"
            >
              <span className="flex items-center gap-2">
                <FaGithub className="text-base" />
                Star us on GitHub
              </span>
              <FaStar className="text-xs transition-transform group-hover:scale-110" />
            </a>
          </div>
        )}
      </div>
    </nav>
  );
};

export default Navbar;
