//
// Created by zfzhou on 1/14/2019.
//
#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    int l = 1, r = x;

    while(l <= r) {
        int m = l + (r-l)/2;
        if(m == x / m)
            return m;
        else if(m < x / m) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return r;
}

/* f(X) = X^2-n
 * 求f(X)=f(X0)+f'(X0)(X-X0)=0的根
 * 即f(Xn)+f'(Xn)(Xn+1-Xn)=0
 * Xn+1 = Xn - f(Xn) / f(Xn+1)
 */
int mySqrt1(int x) {
    long r = x;
    while(r * r > x) {
        r = (r + x / r) / 2;
    }
    return (int)r;
}

double mySqrt2(int x) {
    double l = 0, r = x, precision=1e-6;
    double m;
    while(l <= r) {
        m = l + (r-l) / 2;
        if(abs(m*m-x) < precision) {
            return m;
        } else if(m*m < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return (l+r)/2;
}

/*
int main()
{
    cout << mySqrt(8) << endl;
    printf("%.6f\n", mySqrt2(8));
    return 0;
}
*/
