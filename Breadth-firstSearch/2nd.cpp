//
// Created by zfzhou on 2019/1/20.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;

static struct node {
    int x, y;
    int step;
}S, T, Node;    //S为起点，T为终点，Node为临时结点

int n = 5, m = 5;
char maze[maxn][maxn];
bool inq[maxn][maxn]={false};

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool test(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m)  return false;
    if(maze[x][y] == '*')   return false;
    if(inq[x][y] == true)   return false;
    return  true;
}

static int BFS() {
    queue<node> q;
    q.push(S);
    while(!q.empty()) {
        node top = q.front();   //取出队首元素
        q.pop();
        if(top.x == T.x && top.y == T.y)
            return top.step;
        for(int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(test(newX, newY)) {
                Node.x = newX, Node.y = newY;
                Node.step = top.step+1; //Node层数为top层数加1
                q.push(Node);
                inq[newX][newY] = true; //设置(newX, newY)入过队
            }
        }
    }
    return -1;
}

/*int main()
{
//    int n = 5, m = 5;
    //scanf("%d%d", &n, &m);
    //char maze[n][m+1];
    char temp[5][5] = {{'.', '.', '.', '.', '.'},
                       {'.', '*', '.', '*', '.'},
                       {'.', '*', 'S', '*', '.'},
                       {'.', '*', '*', '*', '.'},
                       {'.', '.', '.', 'T', '*'}};
    // for(int i = 0; i < n; i++) {
    //     getchar();  //过滤掉每行后面的换行符
    //     for(int j = 0; j < m; j++) {
    //         scanf("%c", &maze[i][j]);
    //     }
    //     maze[i][m] = '\0';
    // }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            maze[i][j] = temp[i][j];
        }
    }
    S.x = 2, S.y = 2, T.x = 4, T.y = 3;
    S.step = 0;
    cout << BFS() << endl;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         printf("%c", maze[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
*/


