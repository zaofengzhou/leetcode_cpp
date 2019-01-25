//
// Created by zfzhou on 1/18/2019.
//
#include <bits/stdc++.h>
using namespace std;
#include "../Util/vectorTraverse.h"

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty())  return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int left[n], right[n], height[n];
    fill_n(left, n ,0); fill_n(right, n, n); fill_n(height, n, 0);
    int maxA = 0;
    for(int i = 0; i < m; i++) {
        int cur_left=0, cur_right=n;
        for(int j=0; j<n; j++) {
            if(matrix[i][j]=='1')   height[j]++;
            else    height[j]=0;
        }
        for(int j=0; j<n; j++) {    //compute left(from left to right)
            if(matrix[i][j]=='1')   left[j]=max(left[j], cur_left);
            else { left[j]=0; cur_left=j+1;}
        }
        for(int j=n-1; j>=0; j--) { //compute right(from right to left)
            if(matrix[i][j]=='1')   right[j]=min(right[j], cur_right);
            else { right[j]=n; cur_right=j;}
        }
        for(int j=0; j < n; j++) {
            maxA = max(maxA, (right[j]-left[j])*height[j]);
        }
    }
    return maxA;
}

/*
int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    //printVector(matrix);
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
*/

