#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    unsigned a = 0x1;
    int count = 0;
    for(int i = 0; i < 32; i++) {
        if( (n & a) != 0) {
            count++;
        }
        n = n >> 1;
    }   
    return count;
}

/*
int main()
{
    cout << hammingWeight(11) << endl;
    cout << hammingWeight(128) << endl;
    return 0;
}
*/
