//
// Created by zfzhou on 2019/1/17.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 给出一个m*n的矩阵，矩阵中的元素为0或1。称位置(x, y)与其上下左右四个位置(x,y+1)、(x,y-1)、(x+1,y)、(x-1，y)
 * 是相邻的。如果矩阵中有若干个1是相邻的(不必两两相邻)，那么称这些1构成了一个"块"。求给定的矩阵中"块"的个数。
       0 1 1 1 0 0 1
       0 0 1 0 0 0 0
       0 0 0 0 1 0 0
       0 0 0 1 1 1 0
       1 1 1 0 1 0 0
       1 1 1 1 0 0 0

 * 例如上面的6*7的矩阵中，"块"的个数为4。
 */
/*
const int maxn = 100;
struct node {
    int x, y;   //位置(x, y)
} Node;

int n, m;   //矩阵大小为n*m
int matrix[maxn][maxn]; //01矩阵
bool inq[maxn][maxn] = {false}; //记录(x,y)是否入过队
bool visited[maxn][maxn] = {false};
int X[4] = {0 , 0, 1, -1};
int Y[4] = {1 , -1, 0, 0};

bool judge(int x, int y) {  //判断坐标(x, y)是否需要访问
    // 越界返回false
    if(x < 0 || y < 0 || x >= n || y >= m)    return false;
    // 当前位置为0，或(x, y)已入过队，返回false
    if(matrix[x][y] == 0 || inq[x][y] == true)   return false;
    return true;
}

static void DFS(int x, int y) {
    if(matrix[x][y] == 0)
        return;
    if(x < 0 || y < 0 || x >= n || y >= m)
        return;
    if(visited[x][y])   return;

    visited[x][y] = true;
    DFS(x, y+1);
    DFS(x, y-1);
    DFS(x+1, y);
    DFS(x-1, y);
}

static void BFS(int x, int y) {
    queue<node> q;  //定义队列
    Node.x = x, Node.y = y;
    q.push(Node);   //将结点Node入队
    inq[x][y] = true;   //设置(x, y)已入过队
    while(!q.empty()) {
        node top = q.front();   //取出队首元素
        q.pop();
        for(int i = 0; i < 4; i++) {    //访问与(x, y)相邻的位置
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY)) { //位置(newX, newY)有效
                //设置Node的坐标为(newX, newY)
                Node.x = newX, Node.y = newY;
                q.push(Node);
                inq[newX][newY] = true; //设置位置(newX, newY)已入过队
            }
        }
    }
}
*/

/*
int main()
{
    n = 6, m = 7;
    int matrix1[][7] = {{0, 1, 1, 1, 0, 0, 1},
                        {0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1, 0, 0},
                        {1, 1, 1, 1, 0, 0, 0}};
//    scanf("%d%d", &n, &m);
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            scanf("%d", &matrix[i][j]);
//        }
//    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix[i][j] = matrix1[i][j];
        }
    }
    int ans = 0;    //存放块数
//    for(int x = 0; x < n; x++) {  //枚举每一个位置
//        for(int y = 0; y < m; y++) {
//            if(matrix[x][y] == 1 && inq[x][y] == false) {
//                ans++;    //块数加1
//                BFS(x, y);    //访问整个块，将该块所有"1"的inq都标记为true
//            }
//        }
//    }
    //DFS
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(matrix[x][y] == 1 && visited[x][y] == false) {
                ans++;
                DFS(x, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
*/
