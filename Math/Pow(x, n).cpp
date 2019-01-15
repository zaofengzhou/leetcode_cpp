//
// Created by zfzhou on 1/14/2019.
//
/**
 *
 */
#include <bits/stdc++.h>
using namespace std;

double f(double x, int n) {
    if(n == 0)
        return 1.0;
    double half = f(x, n/2);
    if(n % 2 != 0)
        return half * half * x;
    else
        return half * half;
}

double myPow(double x, int n) {
    if(n < 0)
        return 1 / f(x, n);
    else
        return f(x, n);
}

//iterative log(n)
/*
 * N = 9 = 2^3 + 2^0 = 1001 in binary. Then:
 * x^9 = x^(2^3) * x^(2^0)
 * 可以看见每当我们在二进制N中遇到1时，我们需要累乘x^(2^i)，i是指数的第i位。
 */
double myPow1(double x, int n) {
    double ans = 1;
    long absN = abs((long)n);
    while(absN > 0) {
        if((absN&1)==1) ans *= x;
        absN >>= 1;
        x *= x;
    }
    return n < 0 ? 1/ans : ans;
}

/*
int main()
{
    double x = 2.000000, n = 10;
    //double x = 2.000000, n = -2;
    //cout << myPow(x, n) << endl;
    printf("%.6f\n", myPow(x, n));
    printf("%.6f\n", myPow1(x, n));
    return 0;
}
*/

