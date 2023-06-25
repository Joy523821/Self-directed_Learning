#include<bits/stdc++.h>
using namespace std;
//一個二維陣列紀錄網格座標 一個二維陣列紀錄每個跑過了沒()跑過就跳過
const int MAXN = 3010;
int graph[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n,m;//長 寬
int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};
int maxC = 0; //最大連通分量
int nowConnectedCnt = 0;//現在這團的連通分量    

void dfs(int x,int y){
    nowConnectedCnt++;
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        if(x+dx[i]<0 || x+dx[i]>=n || y+dy[i]<0 || y+dy[i]>=m) continue;//out of range
        if(graph[x+dx[i]][y+dy[i]] == graph[x][y] && !visited[x+dx[i]][y+dy[i]]){ //有連通且沒跑過
            //cout <<"from pt "<<x<<','<<y<<" visit pt "<<x+dx[i]<<','<<y+dy[i]<<" connectC= "<<nowConnectedCnt<<'\n';///測試輸出
            dfs(x+dx[i], y+dy[i]);
        } 
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    for(int i = 0; i < n; i++){//存圖
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) continue;
            nowConnectedCnt = 0;
            dfs(i,j);
            maxC = max(maxC, nowConnectedCnt);
        }
    }

    /*for(int i = 0; i < n; i++){/////測試輸出
        for(int j = 0; j < m; j++){
            cout << visited[i][j]; 
        }cout << '\n';
    }*/

    cout << maxC << '\n';

}