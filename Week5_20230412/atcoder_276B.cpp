#include <bits/stdc++.h>
using namespace std; 

//這到底算鄰接串列還是set?

int main(){
    int n,m,temp,temp2; //n cities , m lines
    cin >> n >> m;

    vector< set<int> > list(n+1); //每個城市自己連到那些

    while(m--){
        cin >> temp >> temp2;
        list[temp].insert(temp2); //記錄誰連誰
        list[temp2].insert(temp);
    }

    for(int i = 1;i<n+1;i++){ //每個城市
        cout << list[i].size();
        for(auto it : list[i]){
            cout << " " << it; //連到誰
        }
        cout << "\n";
    }
}