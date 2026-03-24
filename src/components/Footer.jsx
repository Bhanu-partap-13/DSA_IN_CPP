import React from "react";
import { Link } from "react-router-dom";
import { FaGithub, FaTwitter, FaHeart } from "react-icons/fa";
import { SiLinkedin, SiGithub, SiBuymeacoffee } from "react-icons/si";

const Footer = () => {
  const navigationLinks = [
    { label: "Home", to: "/" },
    { label: "Topics", to: "/all-topics" },
    { label: "LeetCode", to: "/leetcode" },
    { label: "Problems", to: "/problems" }
  ];

  const resourceLinks = [
    {
      label: "Repository",
      href: "https://github.com/Bhanu-partap-13/30-Days-Of-CPP"
    },
    {
      label: "MIT License",
      href: "https://github.com/Bhanu-partap-13/30-Days-Of-CPP/blob/main/LICENSE"
    }
  ];

  const socialLinks = [
    {
      name: "GitHub",
      url: "https://github.com/Bhanu-partap-13",
      icon: <SiGithub />,
      hoverColor: "hover:text-gray-900 dark:hover:text-white",
      bgHover: "hover:bg-gray-200/80 dark:hover:bg-gray-700/70"
    },
    {
      name: "LinkedIn",
      url: "https://www.linkedin.com/in/bhanu-partap-a49084274/",
      icon: <SiLinkedin />,
      hoverColor: "hover:text-blue-600 dark:hover:text-blue-400",
      bgHover: "hover:bg-blue-100/70 dark:hover:bg-blue-900/30"
    },
    {
      name: "Twitter",
      url: "https://twitter.com/bhanupartap59",
      icon: <FaTwitter />,
      hoverColor: "hover:text-sky-500 dark:hover:text-sky-400",
      bgHover: "hover:bg-sky-100/70 dark:hover:bg-sky-900/30"
    },
    {
      name: "Buy Me a Coffee",
      url: "https://buymeacoffee.com/bhanupartap13",
      icon: <SiBuymeacoffee />,
      hoverColor: "hover:text-yellow-600 dark:hover:text-yellow-400",
      bgHover: "hover:bg-yellow-100/70 dark:hover:bg-yellow-900/30"
    }
  ];

  return (
    <footer className="relative mt-auto overflow-hidden border-t border-slate-200/80 bg-gradient-to-b from-white via-slate-50 to-slate-100 dark:border-slate-800 dark:from-slate-950 dark:via-slate-900 dark:to-slate-950">
      <div className="pointer-events-none absolute inset-0">
        <div className="absolute -left-16 top-8 h-36 w-36 rounded-full bg-blue-400/20 blur-3xl dark:bg-blue-500/20" />
        <div className="absolute -right-10 bottom-10 h-40 w-40 rounded-full bg-cyan-300/20 blur-3xl dark:bg-cyan-500/20" />
      </div>

      <div className="absolute top-0 left-0 right-0 h-px bg-gradient-to-r from-transparent via-blue-400/70 to-transparent dark:via-blue-500/70" />

      <div className="relative mx-auto grid max-w-7xl gap-10 px-4 py-12 sm:px-6 lg:grid-cols-[1.35fr_1fr] lg:px-8 lg:py-14">
        <div>
          <span className="inline-flex items-center rounded-full border border-blue-200 bg-blue-50 px-3 py-1 text-xs font-semibold tracking-wide text-blue-700 dark:border-blue-500/40 dark:bg-blue-500/10 dark:text-blue-300">
            Learn. Build. Grow.
          </span>

          <h3 className="mt-4 text-2xl font-bold leading-tight text-slate-900 dark:text-white sm:text-3xl">
            Build strong C++ roots,
            <span className="bg-gradient-to-r from-blue-600 to-cyan-500 bg-clip-text text-transparent dark:from-blue-400 dark:to-cyan-300"> one day at a time.</span>
          </h3>

          <p className="mt-3 max-w-2xl text-sm leading-relaxed text-slate-600 dark:text-slate-300 sm:text-base">
            30 Days of C++ is designed as a progressive learning path. Keep momentum, practice consistently,
            and let every solved problem become a new branch in your programming journey.
          </p>

          <div className="mt-7 flex flex-wrap gap-2">
            {navigationLinks.map((link) => (
              <Link
                key={link.label}
                to={link.to}
                className="rounded-full border border-slate-200 bg-white/80 px-4 py-2 text-sm font-medium text-slate-700 transition-colors hover:border-blue-300 hover:text-blue-700 dark:border-slate-700 dark:bg-slate-900/80 dark:text-slate-200 dark:hover:border-blue-400 dark:hover:text-blue-300"
              >
                {link.label}
              </Link>
            ))}
          </div>

          <div className="mt-6 flex flex-wrap gap-x-5 gap-y-2 text-sm">
            {resourceLinks.map((link) => (
              <a
                key={link.label}
                href={link.href}
                target="_blank"
                rel="noopener noreferrer"
                className="text-slate-600 underline-offset-4 transition-colors hover:text-blue-600 hover:underline dark:text-slate-300 dark:hover:text-blue-300"
              >
                {link.label}
              </a>
            ))}
          </div>
        </div>

        <div className="flex flex-col justify-between gap-6 rounded-2xl border border-slate-200/80 bg-white/70 p-5 shadow-sm backdrop-blur-sm dark:border-slate-700 dark:bg-slate-900/70">
          <div>
            <p className="text-sm font-semibold text-slate-800 dark:text-slate-200">Community</p>
            <p className="mt-1 text-sm text-slate-600 dark:text-slate-400">
              Connect, collaborate, and support the project.
            </p>
          </div>

          <div className="flex flex-wrap gap-2">
            {socialLinks.map((link) => (
              <a
                key={link.name}
                href={link.url}
                target="_blank"
                rel="noopener noreferrer"
                className={`group rounded-xl bg-slate-100 p-3 text-lg text-slate-600 ${link.hoverColor} ${link.bgHover} transition-all duration-200 hover:-translate-y-0.5 dark:bg-slate-800 dark:text-slate-300`}
                aria-label={link.name}
                title={link.name}
              >
                {link.icon}
              </a>
            ))}
          </div>

          <div className="rounded-xl border border-blue-100 bg-blue-50/70 p-4 dark:border-blue-500/30 dark:bg-blue-500/10">
            <p className="text-xs font-semibold uppercase tracking-[0.14em] text-blue-700 dark:text-blue-300">
              Learning Tree
            </p>
            <div className="mt-3 flex items-center gap-4">
              <svg
                viewBox="0 0 120 120"
                className="h-20 w-20 flex-none"
                aria-hidden="true"
              >
                <defs>
                  <linearGradient id="treeStroke" x1="0" y1="0" x2="1" y2="1">
                    <stop offset="0%" stopColor="#2563eb" />
                    <stop offset="100%" stopColor="#06b6d4" />
                  </linearGradient>
                </defs>
                <path d="M60 96 V24" stroke="url(#treeStroke)" strokeWidth="4" strokeLinecap="round" />
                <path d="M60 42 L38 30" stroke="url(#treeStroke)" strokeWidth="3" strokeLinecap="round" />
                <path d="M60 52 L82 40" stroke="url(#treeStroke)" strokeWidth="3" strokeLinecap="round" />
                <path d="M60 64 L34 58" stroke="url(#treeStroke)" strokeWidth="3" strokeLinecap="round" />
                <path d="M60 72 L86 70" stroke="url(#treeStroke)" strokeWidth="3" strokeLinecap="round" />
                <circle cx="60" cy="20" r="9" fill="#1d4ed8" />
                <circle cx="34" cy="28" r="7" fill="#3b82f6" />
                <circle cx="86" cy="38" r="7" fill="#0ea5e9" />
                <circle cx="30" cy="58" r="7" fill="#2563eb" />
                <circle cx="90" cy="70" r="7" fill="#06b6d4" />
                <rect x="52" y="95" width="16" height="12" rx="3" fill="#334155" />
              </svg>

              <p className="text-sm leading-relaxed text-slate-700 dark:text-slate-300">
                Every concept is a branch. Every challenge solved strengthens your foundation.
              </p>
            </div>
          </div>
        </div>
      </div>

      <div className="relative border-t border-slate-200/80 px-4 py-5 text-center text-sm text-slate-600 dark:border-slate-800 dark:text-slate-400">
        &copy; {new Date().getFullYear()} 30 Days of C++. Crafted with <FaHeart className="mx-1 inline text-rose-500" /> by{" "}
        <a
          href="https://github.com/Bhanu-partap-13"
          target="_blank"
          rel="noopener noreferrer"
          className="font-semibold text-blue-600 hover:text-blue-700 dark:text-blue-400 dark:hover:text-blue-300"
        >
          Bhanu Partap
        </a>
      </div>
    </footer>
  );
};

export default Footer;

// 30 Days of C++ - By bhanu partap - learn more about me at https://github.com/Bhanu-partap-13