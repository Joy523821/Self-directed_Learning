#include<bits/stdc++.h>
using namespace std;
//一個二維陣列紀錄網格座標 一個二維陣列紀錄每個跑過了沒()跑過就跳過
const int MAXN = 105;
int graph[MAXN][MAXN];
bool visited[MAXN][MAXN];
int w,h;//寬 高
int dx[] = {-1,1,0,0,-1,-1, 1,1};
int dy[] = {0,0,-1,1, 1,-1,-1,1};   

void dfs(int x,int y){
    visited[x][y] = 1;
    for(int i = 0; i < 8; i++){
        if(x+dx[i]<0 || x+dx[i]>=h || y+dy[i]<0 || y+dy[i]>=w) continue;//out of range
        if(graph[x+dx[i]][y+dy[i]] == graph[x][y] && !visited[x+dx[i]][y+dy[i]]){ //有連通且沒跑過
            //cout <<"from pt "<<x<<','<<y<<" visit pt "<<x+dx[i]<<','<<y+dy[i]<<" connectC= "<<nowConnectedCnt<<'\n';///測試輸出
            dfs(x+dx[i], y+dy[i]);
        } 
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(visited, 0, sizeof(visited));
    cin >> w >> h;
    for(int i = 0; i < h; i++){//存圖
        string tmp;
        cin >> tmp;
        for(int j = 0; j < w; j++){ //- G W B == 0 1 2 3
            if(tmp[j] == '-'){
                graph[i][j] = 0;
            }else if(tmp[j] == 'G'){
                graph[i][j] = 1;
            }else if(tmp[j] == 'W'){
                graph[i][j] = 2;
            }else if(tmp[j] == 'B'){
                graph[i][j] = 3;
            }
        }
    }
    
    int emptyCnt=0, greenCnt=0; //連通分量個數
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(visited[i][j]) continue;
            dfs(i,j);
            if(graph[i][j] == 0){ //空地
                emptyCnt++;
            }else if(graph[i][j] == 1){
                greenCnt++;
            }
        }
    }

    /*for(int i = 0; i < n; i++){/////測試輸出
        for(int j = 0; j < m; j++){
            cout << visited[i][j]; 
        }cout << '\n';
    }*/

    cout << greenCnt << ' ' << emptyCnt << '\n';

}