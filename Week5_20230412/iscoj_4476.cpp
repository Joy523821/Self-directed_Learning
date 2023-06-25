#include<bits/stdc++.h>
using namespace std;

map<int, int> ramen; //重量 幾碗

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int weight;
        cin >> weight;
        if(ramen[weight]){ //有點過
            cout << "Y " << ramen[weight] << "\n";
        }else{
            cout << "N\n";
        }
        ramen[weight]++; //記錄點過多一次
    }
}