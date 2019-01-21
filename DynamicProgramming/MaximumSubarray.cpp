//
// Created by zfzhou on 1/17/2019.
//
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int dp[n];  //dp[i] means the maximum subarray ending with num[i]
    memset(dp, 0, sizeof(dp));
    dp[0] = nums[0];
    int maxV = dp[0];

    for(int i = 1; i < n; i++) {
        dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
        maxV = max(maxV, dp[i]);
    }
    return maxV;
}

/*
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int a[3];
    memset(a, 0, sizeof(a));
    //cout << sizeof(a) << endl;
    cout << maxSubArray(nums) << endl;
    return 0;
}
*/
