//
// Created by zfzhou on 1/23/2019.
//
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
 */

#include<bits/stdc++.h>
using namespace std;

// dp[i][j] means the maximal size of the square that can be achieved at point (i, j)
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0)
        return 0;
    int m = matrix.size(), n = matrix[0].size(), sz = 0;    //sz for the maximum size of the square
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j] - '0';
        sz = max(sz, dp[0][j]);
    }
    for(int i = 1; i < m; i++) {
        dp[i][0] = matrix[i][0] - '0';
        sz = max(sz, dp[i][0]);
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == '1') {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                sz = max(sz, dp[i][j]);
            }
        }
    }
    return sz*sz;
}

int maximalSquare1(vector<vector<char>>& matrix) {
    if(matrix.size() == 0)
        return 0;
    int m = matrix.size(), n = matrix[0].size(), sz = 0, pre = 0;
    // make all the m rows the same by padding a 0 row on the top
    vector<int> dp(m+1, 0);
    for(int j = 0; j < n; j++) {
        for(int i = 1; i <= m; i++) {
            int temp = dp[i];
            if(matrix[i-1][j] == '1') {
                dp[i] = min(dp[i], min(dp[i-1], pre)) + 1;
                sz = max(sz, dp[i]);
            } else {
                dp[i] = 0;
            }
            pre = temp;
        }
    }
    return sz*sz;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    cout << maximalSquare(matrix) << endl;
    cout << maximalSquare1(matrix) << endl;
    return 0;
}
