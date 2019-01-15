//
// Created by zfzhou on 1/15/2019.
//
#include <bits/stdc++.h>
using namespace std;

static vector<string> getNeighbors(string word, unordered_set<string>& wordDict) {
    vector<string> res;
    for(int p = 0; p < (int)word.length(); p++) {
        char letter = word[p];
        for(int k = 0; k < 26; k++) {
            if(letter == 'a' + k) continue;
            word[p] = 'a' + k;
            if(wordDict.find(word) != wordDict.end()) {
                res.push_back(word);
                wordDict.erase(word);
            }
        }
        word[p] = letter;
    }
    return res;
}

/*vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;

    unordered_set<string> wordDict(wordList.begin(), wordList.end());
    queue<string> toVisit;
    addNextWords(beginWord, wordDict, toVisit);

    while(!toVisit.empty()) {
        int num = toVisit.size();   //统计当前层数的结点数
        vector<string> temp;

        for(int i = 0; i < num; i++) {
            string word = toVisit.front();
            temp.push_back(word);
            toVisit.pop();
//            if(word == endWord)
//                return res;
            addNextWords(word, wordDict, toVisit);
        }
        res.push_back(temp);
    }
    return res;
}*/

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    unordered_set<string> wordDict(wordList.begin(), wordList.end());
//    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);
    vector<string> res = getNeighbors("hot", wordDict);
    for(auto s : res) {
        cout << s << " ";
    }

//    for(auto v : res) {
//        for(auto s : v) {
//            cout << s << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
