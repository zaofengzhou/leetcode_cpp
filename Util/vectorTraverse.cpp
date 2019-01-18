//
// Created by zfzhou on 1/18/2019.
//

#include "vectorTraverse.h"
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<vector<char>> res) {
    for (auto v : res) {
        for(auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
}