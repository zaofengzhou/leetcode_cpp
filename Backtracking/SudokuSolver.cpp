//
// Created by zfzhou on 2019/1/13.
//
#include "/Users/zfzhou/stdc++.h"
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for(int i = 0; i < 9; i++) {
        if(board[i][col] != '.' && board[i][col] == c)    return false;
        if(board[row][i] != '.' && board[row][i] == c)    return false;
        if(board[3*(row/3) + i / 3][3*(col/3) + i % 3] != '.' &&
          board[3*(row/3) + i / 3][3*(col/3) + i % 3] == c)   return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if(board[i][j] == '.') {
                for(char c = '1'; c <= '9'; c++) {  //trial. Try 1 through 9
                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;    //Put c for this cell

                        if(solve(board))
                            return true;    //If it's the solution return true
                        else
                            board[i][j] = '.'; //Otherwise go back
                    }
                }

                return false;   //c for this cell is not valid
            }
        }
    }
    return true;
}

bool isValid1(vector<vector<char>>& board, int row, int col, char c) {
    int blrow = (row / 3) * 3, blcol = (col / 3) * 3;
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == c ||  board[row][i] == c ||
        board[blrow+i/3][blcol+i%3] == c)
            return false;
    }
    return true;
}

bool doSolve(vector<vector<char>>& board, int row, int col) {
    for(int i = row; i < 9; i++, col = 0) {
        for(int j = col; j < 9; j++) {
            if(board[i][j] != '.')  continue;
            for(char c = '1'; c <= '9'; c++) {
                if(isValid1(board, i, j, c)) {
                    board[i][j] = c;
                    if(doSolve(board, i, j+1))
                        return true;
                    board[i][j] = '.';
                }
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    if(board.size() == 0)
        return;
    solve(board);
}

void solveSudoku1(vector<vector<char>>& board) {
    if(board.size() == 0)
        return;
    doSolve(board, 0, 0);
}

/*
int main()
{
//    char b[][9]= { {'5','3','.','.','7','.','.','.','.'},
//                    {'6','.','.','1','9','5','.','.','.'},
//                    {'.','9','8','.','.','.','.','6','.'},
//                    {'8','.','.','.','6','.','.','.','3'},
//                    {'4','.','.','8','.','3','.','.','1'},
//                    {'7','.','.','.','2','.','.','.','6'},
//                    {'.','6','.','.','.','.','2','8','.'},
//                    {'.','.','.','4','1','9','.','.','5'},
//                    {'.','.','.','.','8','.','.','7','9'}
//        };

    vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},
                                   {'6','.','.','1','9','5','.','.','.'},
                                   {'.','9','8','.','.','.','.','6','.'},
                                   {'8','.','.','.','6','.','.','.','3'},
                                   {'4','.','.','8','.','3','.','.','1'},
                                   {'7','.','.','.','2','.','.','.','6'},
                                   {'.','6','.','.','.','.','2','8','.'},
                                   {'.','.','.','4','1','9','.','.','5'},
                                   {'.','.','.','.','8','.','.','7','9'}
    };
    for(auto v : board) {
        for(auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
    //solveSudoku(board);
   solveSudoku1(board);
    for(auto v : board) {
        for(auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "helloworld" << endl;
    return 0;
}
*/
