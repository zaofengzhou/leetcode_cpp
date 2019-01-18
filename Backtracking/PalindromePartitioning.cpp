//
// Created by zfzhou on 1/18/2019.
//
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int begin, int end) {
    while (begin < end) {
        if(s[begin++] != s[end--])
            return false;
    }
    return true;
}

static void backtrack(string s, int start, vector<string>& temp, vector<vector<string>>& res) {
    if(start == s.size())
        res.push_back(temp);
    for(int i = start; i < s.size(); i++) {
        if(isPalindrome(s, start, i)) {
            temp.push_back(s.substr(start, i-start+1));
            backtrack(s, i+1, temp, res);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> temp;
    backtrack(s, 0, temp, res);
    return res;
}

/*
int main()
{
    string s = "aab";
    //cout << s.substr(0, 3) << endl;
    vector<vector<string>> res = partition(s);
    for(auto v : res) {
        for(auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
