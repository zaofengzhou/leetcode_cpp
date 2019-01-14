//
// Created by zfzhou on 2019/1/13.
//
#include "/Users/zfzhou/stdc++.h"
using namespace std;

static void backtrack(vector<int>& candidates, int remain, int start, vector<int>& temp, vector<vector<int>>& res) {
    if(remain < 0)
        return;
    if(remain == 0)
        res.push_back(temp);

    for (int i = start; i < candidates.size(); ++i) {
        if(i > start && candidates[i] == candidates[i-1])
            continue;
        temp.push_back(candidates[i]);
        backtrack(candidates, remain-candidates[i], i+1, temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(candidates, target, 0, temp, res);
    return res;
}

/*
int main()
{
    int a[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates(a, a+7);
    vector<vector<int>> res = combinationSum2(candidates, 8);
    for(auto v : res) {
        for (auto a : v) {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
*/


