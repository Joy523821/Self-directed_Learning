#include<bits/stdc++.h>
using namespace std;
/*
    自己: 1 2 4 7 9
    他: 1 3 5 10 11
    迭代自己 如果贏不了他就換自己的下一隻馬
    贏了就他的馬pos++
*/


long long  a[10005],b[10005],c[10005],tmp[10005];
int n,k;

bool check(int day){
    for(int i = 0; i < n; i++){
        tmp[i] = a[i] + b[i]*day;
    }
    sort(tmp,tmp+n,less<long long>());//小到大 記得tmp會爆int ㄟ
    int wins =0 ;//用c[index] 且wins正好等於index
    for(int i = 0; i < n; i++){
        if(tmp[i] <= c[wins]){ //贏不了就換強一點的馬
            continue;
        }
        wins ++;//贏了!! (換下一個敵人)
        if(wins >= k) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
        for(int i = 0; i < n; i++) cin >> c[i];
        sort(c,c+n,less<long long>()); //小到大

        //0000000111111
        //       ^
        int l = 0, r = 1e8+7;
        while(l < r){
            int mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        if(l == 1e8+7) cout << "-1\n";
        else cout << l << "\n";
    }
    
}