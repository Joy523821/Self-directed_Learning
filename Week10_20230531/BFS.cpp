#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int source, vector<vector<int> >& graph){ //回傳每個點bfs距離的陣列，source是淹水起點，graph記得加參考
    queue<int> q; // 接下來要檢測淹水的點
    q.push(source);

    vector<int> distance(graph.size(), INT32_MAX);
    distance[source] = 0;

    while(!q.empty()){ //每次煙一個點它周圍沒被淹過的點加到佇列最後，所以沒有東西在佇列就表示已經跑過整張圖了
        int &current = q.front();

        for(auto& n : graph[current]){ //跑點cur的周圍所有點
            if(distance[n] != INT32_MAX) continue; //淹過了
            distance[n] = distance[current] + 1; //到cur距離+1可以淹到n
            q.push(n);//排到最後面
        }

        q.pop();
    }

    distance[source] = 0;
    return distance;
}

int main(){
    int vCnt, eCnt,source;
    cin >> vCnt >> eCnt >> source;

    vector< vector<int> > graph(vCnt); //鄰接串列

    //吃圖
    int u,v;
    for(int i = 0; i< eCnt; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    vector<int> dis = bfs(source, graph);
    //Output
    for(int i = 0; i < vCnt; i++){
        cout << "distance_"<< i << " = "<< dis[i] << '\n';
    }
}