//
// Created by zfzhou on 2019/1/13.
//
#include <bits/stdc++.h>
using namespace std;

static void backtrack(vector<int>& candidates, int remain, int start, vector<int>& temp, vector<vector<int>>& res) {
    if(remain < 0)
        return;
    if(remain == 0)
        res.push_back(temp);

    for (int i = start; i < candidates.size(); ++i) {
        temp.push_back(candidates[i]);
        backtrack(candidates, remain-candidates[i], i, temp, res);  //数字可以重复
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(candidates, target, 0, temp, res);
    return res;
}

//int main()
//{
//    int a[] = {2, 3, 6, 7};
//    vector<int> candidates(a, a+4);
//    vector<vector<int>> res = combinationSum(candidates, 7);
//    for(auto v : res) {
//        for (auto a : v) {
//            cout << a << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
//
