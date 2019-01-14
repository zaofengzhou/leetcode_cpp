//
// Created by zfzhou on 2019/1/13.
//
#include "/Users/zfzhou/stdc++.h"
using namespace std;

static void backtrack(vector<string>& res, string str, int open, int close, int max) {
    if(str.length() == max*2) {
        res.push_back(str);
    }
    if(open < max)
        backtrack(res, str+"(", open+1, close, max);
    if(close < open)
        backtrack(res, str+")", open, close+1, max);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(res, "", 0, 0, n);
    return res;
}

/*
int main()
{
    vector<string> res = generateParenthesis(3);
    for(auto s : res) {
        cout << s << " ";
    }
    return 0;
}*/
