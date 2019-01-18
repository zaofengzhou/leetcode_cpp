//
// Created by zfzhou on 1/18/2019.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * two points
 * 1.cut[i] is the minimum of cut[j-1] + 1 ( j <= i), if [j, i] is palindrome.
 * 2.if[i, j] is palindrome, [j+1, i-1] is palindrome, and c[j] == c[i].
 *
 * a  b  a  | c  c
 *            j  i
 *      j-1 | [j, i] is palindrome
 * cut(j-1) + 1
 */

int minCut(string s) {
    int n = s.size();
    vector<int> cut(n, 0);
    vector<vector<bool>> pal(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++) {
        int minV = i;
        for(int j = 0; j <= i; j++) {
            if(s[j] == s[i] && (j+1 > i-1 || pal[j+1][i-1])) {
                pal[j][i] = true;
                minV = j==0 ? 0 : min(minV, cut[j-1]+1);
            }
        }
        cut[i] = minV;
    }
    return cut[n-1];
}

/*
int main()
{
    string s = "aab";
    string s1 = "aba";
    cout << s << endl;
    //cout << minCut(s) << endl;
    cout << minCut(s1) << endl;
    return 0;
}
*/
