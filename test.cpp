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

/*
//C
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    memset(a, 0, sizeof(a));
    for(int i = 1; i < n; i++) {
        scanf("%d", a+i);
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] != i) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
*/

/*
//E
int main()
{
    int T;
    scanf("%d", &T);
    int n, m;
    while(T--) {
        scanf("%d%d", &n, &m);
        printf("%d\n", n*m-2);
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

struct mooncake {
    double stock;
    double total;
    double price;
}cake[1010];

bool compare(mooncake a, mooncake b) {
    return a.price > b.price;
}

int main()
{
//    int n;
//    double d;
//    scanf("%d%lf", &n, &d);
//    for(int i = 0; i < n; i++) {
//        scanf("%lf", &cake[i].stock);
//    }
//    for(int i = 0; i < n; i++) {
//        scanf("%lf", &cake[i].total);
//        cake[i].price = cake[i].total / cake[i].stock;
//    }
    int n = 3;
    double d = 20;
    double a[] = {18, 15, 10};
    double b[] = {75, 72, 45};
    for(int i = 0; i < n; i++) {
        cake[i].stock = a[i];
    }
    for(int i = 0; i < n; i++) {
        cake[i].total = b[i];
        cake[i].price = cake[i].total / cake[i].stock;
    }
    sort(cake, cake+n, compare);
    double profit = 0;
    for(int i = 0; i < n; i++) {
        if(cake[i].stock <= d) {
            d -= cake[i].stock;
            profit += cake[i].total;
        } else {
            profit += cake[i].price * d;
            d = 0;
            break;
        }
    }
    printf("%.2f\n", profit);
    return 0;
}
*/
