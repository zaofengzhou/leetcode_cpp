//
// Created by zfzhou on 1/17/2019.
//
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int dp[n];  //dp[i] means the maximum subarray ending with num[i]
    memset(dp, 0, n);
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
    memset(a, 0, 3);
    cout << maxSubArray(nums) << endl;
    return 0;
}
*/
