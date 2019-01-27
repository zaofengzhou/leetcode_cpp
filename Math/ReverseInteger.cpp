//
// Created by zfzhou on 1/25/2019.
//
#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    int sign = x < 0 ? -1 : 1;
    int res = 0;
    int temp = abs(x);
    while(temp > 0) {
        if(INT_MAX / 10 < res || (INT_MAX - temp % 10) < res*10) {
            return 0;
        }
        int m = temp % 10;
        res = res * 10 + m;
        temp /= 10;
    }
    return  sign * res;
}

int reverse1(int x) {
    if(x == INT_MIN)    return 0;
    long long int res = 0;
    long long temp = abs(x);

    while(temp != 0) {
        int m = temp % 10;
        res = res * 10 + m;
        temp /= 10;
    }
    if(res > INT_MAX)   return 0;
    return x >= 0 ? res : -res;
}


/*
int main()
{
//    int a = -pow(2, 31);
//    cout << bitset<32>(a) << endl;
//    cout << reverse(123) << endl;
//    cout << reverse(-123) << endl;
//    cout << reverse(120) << endl;
//    cout << reverse(901000) << endl;
    cout << INT_MAX << endl;
    //cout << reverse(1534236469) << endl;
    cout << reverse(2146847412) << endl;
    cout << reverse(-2147483648) << endl;
    return 0;
}
*/


