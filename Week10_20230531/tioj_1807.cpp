#include <bits/stdc++.h>
using namespace std;
 //map存法
int vCnt, eCnt, u, v;
map <int, set<int> > graph;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> vCnt >> eCnt;
    if (eCnt > (vCnt*(vCnt-1)/2)){
        cout << "Yes\n";
        return 0;
    }
    for (int i = 0; i < eCnt; i++){
        cin >> u >> v;
        if (u == v || (graph.count(u) && graph[u].count(v)) ){ //自環 或是 已經有u且u已經有到v
            cout << "Yes\n";
            return 0;
        }
        graph[u].insert(v);
        graph[v].insert(u);
    }
    cout << "yes\n";
}

//source: https://yuihuang.com/tioj-1807/