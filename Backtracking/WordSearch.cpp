//
// Created by zfzhou on 2019/1/13.
//
#include <bits/stdc++.h>
using namespace std;

static bool dfs(vector<vector<char>>& board, string& word, int index, int y, int x, vector<vector<bool>>& visited) {
    if(index == word.length())
        return true;

    if(y < 0 || x < 0 || y >= board.size() || x >= board[0].size())
        return false;
    if(visited[y][x])   return false;

    if(board[y][x] != word[index])  return false;

    visited[y][x] = true;
    bool exist = dfs(board, word, index+1, y-1, x, visited) ||
            dfs(board, word, index+1, y+1, x, visited) ||
            dfs(board, word, index+1, y, x-1, visited) ||
            dfs(board, word, index+1, y, x+1, visited);
    visited[y][x] = false;
    return exist;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(dfs(board, word, 0, i, j, visited))
                return true;
        }
    }
    return false;
}

/*
int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},
                                   {'S','F','C','S'},
                                   {'A','D','E','E'}};
    string word = "ABCCED";
    string word1 = "SEE";
    string word2 = "ABCB";
    cout << exist(board, word) << endl;
    cout << exist(board, word1) << endl;
    cout << exist(board, word2) << endl;
    return 0;
}
 */


