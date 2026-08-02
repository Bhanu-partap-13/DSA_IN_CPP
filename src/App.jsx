import React, { Suspense, useEffect } from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import { Toaster } from 'react-hot-toast';
import Navbar from "./components/Navbar";
import Footer from "./components/Footer";
import Loader from "./components/Loader";
import { ThemeProvider } from "./contexts/ThemeContext";

// Lazy load pages
const Home = React.lazy(() => import("./pages/Home"));
const Day = React.lazy(() => import("./pages/Day"));
const AllTopics = React.lazy(() => import("./pages/AllTopics"));
const Topics = React.lazy(() => import("./pages/Topics"));
const Leetcode = React.lazy(() => import("./pages/Leetcode"));
const Problems = React.lazy(() => import("./pages/Problems"));
const Codeforces = React.lazy(() => import("./pages/Codeforces"));
const OopsLectures = React.lazy(() => import("./pages/OopsLectures"));
const OopsLectureFiles = React.lazy(() => import("./pages/OopsLectureFiles"));

function App() {
  useEffect(() => {
    // Enable smooth scrolling
    document.documentElement.style.scrollBehavior = 'smooth';
  }, []);

  return (
    <ThemeProvider>
      <Router>
        <div className="flex flex-col min-h-screen bg-gray-50 dark:bg-gray-900 transition-colors duration-300">
          <Navbar />
          <Toaster />
          <main className="flex-1 pt-16">
            <Suspense fallback={<Loader />}>
              <Routes>
                <Route path="/" element={<Home />} />
                <Route path="/day/:dayId" element={<Day />} />
                <Route path="/all-topics" element={<AllTopics />} />
                <Route path="/topics/:topicName" element={<Topics />} />
                <Route path="/leetcode" element={<Leetcode />} />
                <Route path="/problems" element={<Problems />} />
                <Route path="/codeforces" element={<Codeforces />} />
                <Route path="/oops" element={<OopsLectures />} />
                <Route path="/oops/:lectureName" element={<OopsLectureFiles />} />
              </Routes>
            </Suspense>
          </main>
          <Footer />
        </div>
      </Router>
    </ThemeProvider>
  );
}

export default App;


// 30 Days of C++ - By bhanu partap - learn more about me at https://github.com/Bhanu-partap-13