#include<bits/stdc++.h>
using namespace std;

int main(){
    int vCount, eCount;
    cin >> vCount >> eCount;

    vector<vector<bool> > graph;
    graph.assign(vCount, vector<bool>(vCount)); //把graph[0]~graph[vCount-1]的值設成vector<bool>(vCount), 即vector[vCnt][vCnt]
    //好像值預設是0

    int u,v;
    for(int i = 0; i < eCount; i++){
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    //output
    for(int i = 0; i < vCount; i++){
        cout << "v" << i << ":";
        for(int j = 0; j < vCount; j++){
            if(graph[i][j]) cout << ' ' << j;
        }
        cout << '\n';
    }
}