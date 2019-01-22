//
// Created by zfzhou on 1/21/2019.
//
#include <bits/stdc++.h>
using namespace std;

/*
//1
int main()
{
    //long long int origin;
    int n;
    long long X;
    scanf("%d%lld", &n, &X);
    int opt, x;
    int a[n][2];
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &opt, &x);
        a[i][0] = opt;
        a[i][1] = x;
    }
    for(int i = n-1; i >= 0; i--) {
        if(a[i][0] == 1) {
            X -= a[i][1];
        } else if(a[i][0] == 2) {
            X += a[i][1];
        } else if(a[i][0] == 3){
            X /= a[i][1];
        } else if(a[i][0] == 4){
            X *= a[i][1];
        }
    }
    printf("%lld\n", X);
    return 0;
}
*/

//2
/*
int main()
{
    int n;
    scanf("%d", n);
    int a[n+1];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++) {
        scanf("%d", a+i);
    }
    return 0;
}
*/

//3
/*
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    int t = a[0];
    int ans =  t^a[n-1];
    printf("%d\n", ans == 0 ? -1 : ans);
    return 0;
}
*/
