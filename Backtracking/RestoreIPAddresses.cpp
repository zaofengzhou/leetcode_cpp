//
// Created by zfzhou on 2019/1/12.
//
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//"25525511135"
static void backtrack(string s, int idx, int count, string temp, vector<string>& res) {
    if(count > 4)   return;
    if(count == 4 && idx == s.length()) {
        res.push_back(temp);
    }
    for (int i = 1; i < 4; ++i) {
        if(idx+i > s.length())  break;
        string sec = s.substr(idx, i);
        if((sec.length() > 1 && sec[0] == '0') ||
                (sec.length() == 3 && stoi(sec) > 255))  continue;
        backtrack(s, idx+i, count+1, temp+sec+(count==3?"":"."), res);
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string temp;
    backtrack(s, 0, 0, temp, res);
    return res;
}

//int main()
//{
//    vector<string> res = restoreIpAddresses("25525511135");
//    for(auto s: res) {
//        cout << s << endl;
//    }
//    return 0;
//}
