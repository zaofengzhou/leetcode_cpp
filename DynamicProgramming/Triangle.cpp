//
// Created by zfzhou on 1/17/2019.
//
#include <bits/stdc++.h>
using namespace std;

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
static int dfs(vector<vector<int>>& triangle, int row, int col) {
    if(row+1 == triangle.size())    //下一层结点是边界
        return triangle[row][col];
    return triangle[row][col] + min(dfs(triangle, row+1, col), dfs(triangle, row+1, col+1));
}

int minimumTotal1(vector<vector<int>>& triangle) {
    return dfs(triangle, 0, 0);
}

/*
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int dp[n][n];
    memset(dp[0], 0, sizeof(int));
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
    }
    for(int i = 1; i < n; i++) {
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }
    for(int i = 2; i < n; i++) {
        for(int j = 1; j < i; j++) {
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    int minV = INT_MAX;
    for(int i = 0; i < n; i++) {
        minV = min(minV, dp[n-1][i]);
    }
    return minV;
}
*/
/* triangle
 * 2
 * 3 4
 * 6 5 7
 * 4 1 8 3
 *
 * dp[][]
 * 11
 * 9 10
 * 7 6 10
 * 4 1 8 3
 * dp[] //滚动数组
 *
 *
 * 7 6 10
 * 4 1 8 3
 */
int minimumTotal(vector<vector<int>>& triangle)
{
    int n = triangle.size();
    int dp[n][n];
    for(int i = 0; i < n; i++) {
        dp[n-1][i] = triangle[n-1][i];
    }
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
    }
    return dp[0][0];
}

int minimumTotal2(vector<vector<int>>& triangle)
{
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for(int i = n-2; i >= 0; i--) {     // For each layer
        for(int j = 0; j <= i; j++) {   // check its every 'node'
            // Find the lesser of its two children, and sum the current value int the triangle with it.
            minlen[j] = min(minlen[j], minlen[j+1]) + triangle[i][j];
        }
    }
    return minlen[0];
}

/*
int main()
{
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5 ,7},
                                    {4, 1, 8, 3}};
//    for(auto v : triangle) {
//        for(auto c : v) {
//            cout << c << " ";
//        }
//        cout << endl;
//    }
    cout << minimumTotal1(triangle) << endl;    //dfs
    cout << minimumTotal(triangle) << endl;
    cout << minimumTotal2(triangle) << endl;
    return 0;
}
*/
