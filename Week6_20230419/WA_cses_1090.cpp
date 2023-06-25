#include<bits/stdc++.h>
using namespace std;



int weight[200005],n,x; 


bool check(int gondola){ 
    int packed[gondola] = {0}; //packed[i] 第i個車廂已經裝了多重
    int cur = 0; //第i車廂
    for(int people = 0; people < n; people++){
        while(weight[people] + packed[cur] > x){//嘗試把人加進車廂cur 大就cur++再一次
            cur++;
            if(cur >= gondola) return false; 
        } 
        packed[cur] += weight[people];
        cur = 0;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> weight[i];
    sort(weight, weight+n, greater<int>()); //大到小

    int l = 1, r = 200005;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << "\n";
}