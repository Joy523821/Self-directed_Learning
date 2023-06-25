#include<bits/stdc++.h>
using namespace std;

void dfs(int cur,vector<vector<int> > &graph, vector<bool> &visited){
    visited[cur] = 1;//到此一遊

    for(auto &n : graph[cur]){
        if(visited[n]) continue;//那個點已經跑過就不跑了
        cout << "pt from " << cur << "to " << n << '\n';//Output
        dfs(n, graph, visited);//用遞迴取代STACK<INT>
    }
}

int main(){
    int vCount, eCount,dfsPt;
    cin >> vCount >> eCount >> dfsPt;

    vector< vector<int> > graph(vCount);

    int u,v;    
    for(int i = 0; i < eCount; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //給dfs用的 紀錄誰走過
    vector<bool> visited(vCount);
    dfs(dfsPt, graph, visited);
}