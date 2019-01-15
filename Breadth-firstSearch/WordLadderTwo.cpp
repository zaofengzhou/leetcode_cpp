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

// BFS: Trace every node's distance from the start node (level by level).
static void bfs(string start, string end, unordered_set<string>& dict, map<string,
        vector<string>>& nodeNeighbors, map<string, int>& distance) {
    for (string str : dict)
        nodeNeighbors[str] = vector<string>();

    queue<string> queue;
    queue.push(start);
    distance[start] = 0;

    while (!queue.empty()) {
        int count = queue.size();
        bool foundEnd = false;
        for (int i = 0; i < count; i++) {
            string cur = queue.front();
            queue.pop();
            int curDistance = distance[cur];
            vector<string> neighbors = getNeighbors(cur, dict); //cur node neighbors

            for (string neighbor : neighbors) {
                nodeNeighbors[cur].push_back(neighbor);
                if (distance.find(neighbor) == distance.end()) {// Check if visited
                    distance[neighbor] = curDistance + 1;
                    if (end == neighbor)// Found the shortest path
                        foundEnd = true;
                    else
                        queue.push(neighbor);
                }
            }
        }
        if (foundEnd)
            break;
    }
}

// DFS: output all paths with the shortest distance.
static void dfs(string cur, string end, unordered_set<string>& dict, map<string, vector<string>>& nodeNeighbors,
        map<string, int>& distance, vector<string>& solution, vector<vector<string>>& res) {
    solution.push_back(cur);
    if (end == cur) {
        res.push_back(solution);
    } else {
        for (string next : nodeNeighbors[cur]) {
            if (distance[next] == distance[cur] + 1) {
                dfs(next, end, dict, nodeNeighbors, distance, solution, res);
            }
        }
    }
    solution.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    map<string, vector<string>> nodeNeighbors;  // Neighbors for every node
    map<string, int> distance;  // Distance of every node from the start node
    vector<string> solution;

    dict.insert(beginWord);
    bfs(beginWord, endWord, dict, nodeNeighbors, distance);
    dfs(beginWord, endWord, dict, nodeNeighbors, distance, solution, res);
    return res;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);

//    unordered_set<string> wordDict(wordList.begin(), wordList.end());
//    vector<string> res = getNeighbors("dot", wordDict);
//    for(auto s : res) {
//        cout << s << " ";
//    }

    for(auto v : res) {
        for(auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
