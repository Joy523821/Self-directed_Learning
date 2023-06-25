//problem source: https://codeforces.com/contest/276/problem/C
#include<bits/stdc++.h>
using namespace std;
#define usll unsigned long long
/*既然可以隨意排序數列，就只要先計算每項對被取幾次，會取越多次的項給越大的數字就好
  因為每次查詢都是一個區間[l, r]所以用差分紀錄即可
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<usll> vec(n, 0); //數列, 0base紀錄
    for(auto &it:vec) cin>>it; //輸入數列
    sort(vec.begin(), vec.end(), greater<usll>());

    vector<usll> predif(n,0); //計算查詢次數的差分陣列
    while(q--){
        int l,r;
        cin >> l >> r;
        l--; r--; //1base轉0base
        predif[l]++;
        if(r+1 < n) predif[r+1]--;
    }

    for(int i = 1; i < n; i++) predif[i] += predif[i-1]; //還原成數列(各項查詢次數的數列)
    sort(predif.begin(), predif.end(), greater<usll>()); //這樣的話剛好是數列i配上查詢數列i

    usll count = 0;
    for(int i = 0; i < n; i++) count += predif[i]*vec[i];
    cout << count << '\n';
}