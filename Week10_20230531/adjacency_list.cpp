#include<bits/stdc++.h>
using namespace std;

int main(){
    int vCount, eCount;
    cin >> vCount >> eCount;

    vector< vector<int> > graph(vCount);

    int u,v;
    for(int i = 0; i < eCount; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //output
    for(int i = 0; i < vCount; i++){
        cout << 'v' << i << ":";
        for(auto it : graph[i]) cout << " " << it;
        cout <<'\n';
    }
}