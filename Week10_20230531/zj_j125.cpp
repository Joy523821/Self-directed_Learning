#include<bits/stdc++.h>
using namespace std;
/*紀錄整張圖的最大高度差(最高-最低)
  二分搜高度限制=0~最大高度差
  試試看在該高度差限制下能否蓋出步道(用DFS比較快)
  確定最小限制高度之後用BFS求最短距離
*/
int graph[305][305];//存高度
int n,maxH=0,minH=INT32_MAX;//圖大小,圖中最大高度及最低高度
int flag = 0;//能否蓋出步道,給二分搜的DFS用的
int visited[305][305] = {};//DFS用的
int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};//移動方向,DFS用的
int dis[305][305];//距離, BFS用

void dfs(int x,int y,int deltaH){
    visited[x][y] = 1; //到此一遊
    if((x == n && y == n) || flag){ //到了或已確認可蓋所以不用繼續跑
        flag = 1;
        return;
    }
    for(int i = 0; i < 4; i++){//往四方向移動
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<=0 || nx>n || ny<=0 || ny>n) continue; //out of range 
        if(abs(graph[x][y] - graph[nx][ny]) > deltaH || visited[nx][ny]) continue; //高度差太多蓋不了
        dfs(nx, ny, deltaH);
    }
}

queue<int> q;//存要訪問的座標,一次存取兩位(x,y)
void bfs(int x, int y,int deltaH){
    dis[x][y] = 0;
    q.push(x); q.push(y);
    while(!q.empty()){
        int prev_x = q.front(); q.pop();
        int prev_y = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = prev_x+dx[i], ny = prev_y+dy[i];
            if(nx<=0 || nx>n || ny<=0 || ny>n) continue; //out of range
            if(abs(graph[prev_x][prev_y] - graph[nx][ny]) > deltaH || dis[nx][ny] != INT32_MAX) continue; //高度差太多或已經跑過
            dis[nx][ny] = dis[prev_x][prev_y] + 1;
            //cout << "dis " << nx << ',' << ny << '=' << dis[nx][ny] << '\n';///output try
            q.push(nx); q.push(ny);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j]; //1_base
            maxH = max(maxH, graph[i][j]);
            minH = min(minH, graph[i][j]);
        }
    }
    //cout << maxH << ' ' << minH << '\n';/////output try
    //二分搜左閉右開
    int l=-1,r=maxH-minH;
    while(r-l > 1){
        // cout << "bs" << r << ' ' << l << "\n";////output try
        int mid = (l+r)/2;
        memset(visited, 0, sizeof(visited));
        flag = 0;
        dfs(1,1,mid);
        if(flag){ //可以蓋
            r = mid;
        }else{
            l = mid;
        }
    }
    //cout << "bs complete with ret = " << r <<"\n";///output try
    //此時r就是最小高度差，跑BFS求最短距離
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <=n; j++){
            dis[i][j] = INT32_MAX;
        }
    }
    bfs(1,1,r);
    cout << r << '\n' << dis[n][n] << '\n';

}
