//
// Created by zfzhou on 2019/1/16.
//
#include <bits/stdc++.h>
using namespace std;


static void dfs(int index, int n, int sumW, int sumC, int w[], int c[], int& maxValue, int V) {
    if(index == n) {
        if(sumW <= V && sumC > maxValue)
            maxValue = sumC;
        return;
    }

    dfs(index+1, n, sumW, sumC, w, c, maxValue, V);
    dfs(index+1, n, sumW+w[index], sumC+c[index], w, c, maxValue, V);

}

static void dfs1(int index, int n, int sumW, int sumC, int w[], int c[], int& maxValue, int V) {
    if(index == n) {
        return;
    }

    dfs1(index+1, n, sumW, sumC, w, c, maxValue, V);

    if(sumW + w[index] <= V) {  //剪枝
        if(sumC + c[index] > maxValue) {
            maxValue = sumC + c[index];
        }
        dfs1(index+1, n, sumW+w[index], sumC+c[index], w, c, maxValue, V);
    }


}

int main()
{
    int n = 5;
    int w[] = {3, 5, 1, 2, 2};
    int c[] = {4 ,5, 2, 1, 3};
    int V = 8;
    int maxValue = 0;
    //dfs(0, n, 0, 0, w, c, maxValue, V);
    dfs1(0, n, 0, 0, w, c, maxValue, V);

    cout << maxValue << endl;
    return 0;
}