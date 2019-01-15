//
// Created by zfzhou on 2019/1/14.
//
#include <bits/stdc++.h>
using namespace std;

void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
    //wordDict.erase(word);
    for(int p = 0; p < (int)word.length(); p++) {
        char letter = word[p];
        for(int k = 0; k < 26; k++) {
            word[p] = 'a' + k;
            if(wordDict.find(word) != wordDict.end()) {
                toVisit.push(word);
                wordDict.erase(word);
            }
        }
        word[p] = letter;
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordDict(wordList.begin(), wordList.end());
    queue<string> toVisit;
    addNextWords(beginWord, wordDict, toVisit);
    int dist = 2;
    while(!toVisit.empty()) {
        int num = toVisit.size();
        for(int i = 0; i < num; i++) {
            string word = toVisit.front();
            toVisit.pop();
            if(word == endWord) return dist;
            addNextWords(word, wordDict, toVisit);
        }
        dist++;
    }
    return 0;
}

/*
int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << beginWord << endl;
    cout << endWord << endl;
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
 */
