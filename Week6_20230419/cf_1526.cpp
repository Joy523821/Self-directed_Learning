#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    priority_queue<ll, vector<ll>, greater<ll> > drunk; //已經喝的ai小到大
    int n,tmp,count=0; //有幾杯,每杯效果,喝了幾杯
    cin >> n;
    ll hp = 0;

    while(n--){
        cin >> tmp;
        hp += tmp;//乾了啦
        count++;
        drunk.push(tmp);
        if(hp<0){//丟掉一杯
            hp -= drunk.top();
            drunk.pop();
            count--;
        }
    }

    cout << count << "\n";
}