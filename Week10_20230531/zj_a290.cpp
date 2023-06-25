#include<bits/stdc++.h>
using namespace std;

bool graph[805][805]; //1base鄰接矩陣
bool visited[805]; //是否已跑過
int n,m;//n*n方陣 邊數
int flag = 0;//當前測資是否可達

void dfs(int pt, int des){ //現在在哪 目標
    visited[pt] = 1;
    if(pt == des || flag){ //到了或是已經好了
        flag = 1;
        return;
    }
    
    for(int j = 1; j <= n; j++){
        if(graph[pt][j]==1 && !visited[j]){ //可以到的話
        //cout << "dfs " << pt << " to " << j << '\n';///測試輸出
            dfs(j, des);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (cin >> n >> m){
        memset(visited,0,sizeof(visited));
        memset(graph,0,sizeof(graph));
        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            graph[a][b] = 1; //a可到b
        }
        
        int from,to;
        cin >> from >> to;
        dfs(from,to);
        if(flag){
            cout << "Yes!!!\n";
            flag = 0;
        }else{
            cout << "No!!!\n";
        }
    }
    
}