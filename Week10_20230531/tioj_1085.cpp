#include<bits/stdc++.h>
using namespace std;
#define INF 10000000 //距離絕對不可能比這個大

int graph[55][55][55]; //存圖
int dis[55][55][55]; //存深度
int movType[55][55][55]; // 因為只有六種移動方式，只要記錄到達該點是哪種移動方式就等於紀錄上一點在哪裡了
int dx[] = {-1,1,0,0,0,0}, dy[] = {0,0,-1,1,0,0}, dz[] = {0,0,0,0,-1,1};//六種移動方式
int xSize,ySize,zSize; //圖大小
queue<int> q;//bfs用 //一次取三個丟三個(x,y,z)

void printAns(int x, int y, int z){
    if(x==1 && y==1 && z==1){ //跑回起點了
        cout << "(1,1,1)";
        return;
    }
    int type = movType[x][y][z];
    printAns(x-dx[type], y-dy[type], z-dz[type]); //遞迴
    cout << "->(" << x << ',' << y << ',' << z << ")"; //輸出放在呼叫後面，所以會從最深層輸出回來
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> xSize >> ySize >> zSize;
    for(int i = 1; i <= zSize; i++){ //1_base
        for(int j = 1; j <= ySize; j++){
            for(int k = 1; k <= xSize; k++){
                cin >> graph[k][j][i];
                dis[k][j][i] = INF; //預設無限遠
            }
        }
    }
    if(graph[1][1][1] == 1 || graph[xSize][ySize][zSize] == 1){ //起點或終點不給跑
        cout << "no route\n";
        return 0;
    }

    dis[1][1][1] = 0; //bfs起點
    if(graph[1][1][1] == 0) q.push(1); q.push(1); q.push(1); //起點可以走，存入BFS
    while(!q.empty()){
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int z = q.front(); q.pop(); //取值
        for(int i = 0; i < 6; i++){ //跑過六種走法
            int nx = x + dx[i],ny = y + dy[i],nz = z + dz[i]; //下一點
            //printf("(%d,%d,%d)->(%d,%d,%d), graph(npt)=%d\n",x,y,z,nx,ny,nz,graph[nx][ny][nz]);//輸出測試
            if(nx==0||nx>xSize||ny==0||ny>ySize||nz==0||nz>zSize) continue; //out of range
            if(graph[nx][ny][nz] == 1 || dis[nx][ny][nz] != INF) continue; //不能走或是走過了
            dis[nx][ny][nz] = dis[x][y][z] + 1;
            movType[nx][ny][nz] = i; //是用第i種方法到達的
            q.push(nx); q.push(ny); q.push(nz);
        }
    }
    /*
    for(int i = 1; i <= zSize; i++){
        for(int j = 1; j <= ySize; j++){
            for(int k = 1; k <= xSize; k++){
                cout << dis[k][j][i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    } *///輸出測試 

    if(dis[xSize][ySize][zSize] == INF){
        cout << "no route\n";
        return 0;
    }
    //輸出路線
    printAns(xSize,ySize,zSize);
    cout << '\n';

   

}