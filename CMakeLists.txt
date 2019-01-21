cmake_minimum_required(VERSION 3.12)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_cpp Backtracking/RestoreIPAddresses.cpp Backtracking/CombinationSum.cpp Backtracking/CombinationSumTwo.cpp Backtracking/SudokuSolver.cpp Backtracking/GenerateParentheses.cpp Backtracking/WordSearch.cpp README.md Breadth-firstSearch/WordLadder.cpp "Math/Pow(x, n).cpp" "Math/Sqrt(x).cpp" Breadth-firstSearch/WordLadderTwo.cpp Breadth-firstSearch/SurroundedRegions.cpp DynamicProgramming/Triangle.cpp DynamicProgramming/MaximumSubarray.cpp Backtracking/PalindromePartitioning.cpp DynamicProgramming/PalindromePartitioningII.cpp DynamicProgramming/MaximalRectangle.cpp Util/vectorTraverse.cpp Util/vectorTraverse.h Depth-firstSearch/2rd.cpp Breadth-firstSearch/1st.cpp Breadth-firstSearch/2nd.cpp test.cpp DynamicProgramming/CountWays.cpp)

