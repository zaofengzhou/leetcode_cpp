cmake_minimum_required(VERSION 3.12)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_cpp Backtracking/RestoreIPAddresses.cpp Backtracking/CombinationSum.cpp Backtracking/CombinationSumTwo.cpp Backtracking/SudokuSolver.cpp Backtracking/GenerateParentheses.cpp Backtracking/WordSearch.cpp
        README.md Breadth-firstSearch/WordLadder.cpp "Math/Pow(x, n).cpp" "Math/Sqrt(x).cpp" Breadth-firstSearch/WordLadderTwo.cpp)
