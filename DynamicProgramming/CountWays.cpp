//
// Created by zfzhou on 1/21/2019.
//
#include<bits/stdc++.h>
using namespace std;

 /*
有数组penny，penny中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，再给定一个整数aim(小于等于1000)代表要找的钱数，求换钱有多少种方法。

给定数组penny及它的大小(小于等于50)，同时给定一个整数aim，请返回有多少种方法可以凑成aim。

测试样例：
[1,2,4],3,3
返回：2
 */

int process1(vector<int>& penny, int index, int aim) {
    int res = 0;
    if(index == penny.size()) {
        res = aim == 0 ? 1 : 0;
    } else {
        for(int i = 0; penny[index]*i <= aim; i++) {    //枚举每种货币可以使用的张数
            res += process1(penny, index+1, aim-penny[index]*i);
        }
    }
    return res;
}

int countWays(vector<int>& penny, int aim) {
    return process1(penny, 0, aim);
}


int process2(vector<int>& penny, int index, int aim, vector<vector<int>>& map) {
    int res = 0;
    if(index == penny.size()) {
        res = aim == 0 ? 1 : 0;
    } else {
        int mapValue = 0;
        for(int i = 0; penny[index]*i <= aim; i++) {    //枚举每种货币可以使用的张数
            mapValue = map[index+1][aim-penny[index]*i];
            if(mapValue != 0) {
                res += mapValue == -1 ? 0 : mapValue;
            } else {
                res += process2(penny, index+1, aim-penny[index]*i, map);
            }
        }
    }
    map[index][aim] = res == 0 ? -1 : res;
    return res;
}

int coins2(vector<int>& penny, int aim) {
    int n = penny.size();
    vector<vector<int>> map(n+1, vector<int>(aim+1, 0));
    return process2(penny, 0, aim, map);
}

int coins3(vector<int>& penny, int aim) {
    int n = penny.size();
    int dp[n][aim+1];       //dp[i][j]表示用penny[0...i]组成前钱数j的方法数
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for(int j = 1; penny[0]*j <= aim; j++) {
        dp[0][penny[0]*j] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= aim; j++) {
            int num = 0;
            for(int k = 0; j- k*penny[i]>= 0; k++) {    //使用k张penny[i]货币,剩下的钱用penny[0..i-1]组成
                num += dp[i-1][j-k*penny[i]];
            }
            dp[i][j] = num;
        }
    }
    return dp[n-1][aim];
}

/*
int main()
{
    vector<int> penny = {1, 2, 4};
    int aim = 3;
    //cout << aim << endl;
    cout << countWays(penny, aim) << endl;
    cout << coins2(penny, aim) << endl;
    cout << coins3(penny, aim) << endl;
    return 0;
}
*/
