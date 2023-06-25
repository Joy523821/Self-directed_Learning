#include<bits/stdc++.h>
using namespace std;
/*二分圖:紅色只接白色
        白色只接紅色
 所以在遍歷的過程中傳入一個值=0or1
 每次遞迴dfs時反轉
 如果有哪次遍歷發現相鄰是同色表示不是二分
*/
int vC, eC;

bool dfs(int cur,int curColor,vector<vector<int> > &graph, vector<int> &color){ //回傳是否為二分
    //cout << "dfs " << cur << '\n';/////////////////////cout大法
    color[cur] = curColor;

    bool is_binary = 1;
    for(auto& n : graph[cur]){
        //cout << n << " color:" << color[n] << '\n'; ///////////////////////cout大法
        if(color[n] == curColor) return false; //和相鄰點同色不合
        if(color[n] == -1) is_binary = is_binary && dfs(n, curColor^1,graph,color);
        //以跑過而且不同色就甚麼都不做
    }
    return is_binary;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> vC >> eC){
        if(!vC && !eC) break;//輸入==0 EOF
        vector<vector<int> > graph(vC+20);
        int u,v;
        for(int i = 0; i < eC; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

//cout大法
        //cout << "Adjacency List is ready\n";


        vector<int> color(vC+20, -1); //-1沒跑過 0白色 1紅色
        (dfs(1,1,graph,color))? cout << "Yes\n": cout << "No\n";
    }

}