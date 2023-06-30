#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, m, r, c;
    char maze[1000][1000];
    bool visited[1000][1000];
    char ans[1000][1000];
    cin>>n>>m>>r>>c;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }

    char dr[]={0, 1, 0, -1};
    char dc[]={1, 0, -1, 0};
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    ans[r][c]=0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int u = x+dr[i];
            int v = y+dc[i];
            if (u<1||u>)
        }
    }
}