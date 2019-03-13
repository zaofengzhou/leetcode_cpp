#include<bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if(s.empty() || words.empty())  return res;
    int n = words.size(), m = words[0].size();
    unordered_map<string, int> m1;  //统计每个单词的个数
    for(auto s : words) m1[s]++;
    for(int i = 0; i <= s.size()-n * m; i++) {  //从开头开始一个个单词遍历
        unordered_map<string, int> m2;
        int j = 0;
        for(j = 0; j < n; j++) {
            string t = s.substr(i + j * m, m);  //给定单词长度的字串
            if(m1.find(t) == m1.end())  break;
            m2[t]++;
            if(m2[t] > m1[t])   break;
        }
        //正好匹配完给定单词集里所有的单词
        if(j == n)  res.push_back(i);
    }

    return res;
}

/*
int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> res = findSubstring(s, words);
    return 0;
}
*/

