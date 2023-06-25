#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

//從吃最慢的人開始煮
int main(){
    int n; //幾個人
    cin >> n;
    while(n !=0){
        vector<pii> time(n); //pair<吃多久, 做多久>
        for(int i = 0; i < n; i++){
            cin >> time[i].second >> time[i].first; //做多久 吃多久
        }
        sort(time.begin(), time.end(), greater<pii>()); //吃的時間大到小
        long long curTime = 0; //做某人的餐時已經過多久了
        long long maxTime = 0; //要吃多久 <------------資料範圍1000*10000可能會爆int
        for(int i = 0; i < n; i++){
            curTime += time[i].second; //做i的餐
            maxTime = max(maxTime, curTime + time[i].first); //找i個值最大
        } 
        cout << maxTime << "\n";
        
        cin >> n;
    }
}