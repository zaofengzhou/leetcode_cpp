//
// Created by zfzhou on 2019/1/17.
//
#include <bits/stdc++.h>
using namespace std;

static void backtrack(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& res) {
    res.push_back(temp);
    for(int i = start; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        backtrack(nums, i+1, temp, res);
        temp.pop_back();
    }
}

static void backtrack1(vector<int>& nums, int start, int k, vector<int>& temp, vector<vector<int>>& res) {
    if(k == 0)
        res.push_back(temp);
    for(int i = start; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        backtrack1(nums, i+1, k-1, temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(nums, 0, temp, res);
    return res;
}

vector<vector<int>> combination(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    backtrack1(nums, 0, 2, temp, res);
    return res;
}

/*
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    vector<vector<int>> res1 = combination(nums);
//    for(auto v : res) {
//        for(auto a : v) {
//            cout << a << " ";
//        }
//        cout << endl;
//    }
    for(auto v : res1) {
        for(auto a : v) {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
