//題目https://iscoj.fg.tp.edu.tw/problem/4494
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;

int arr[MAXN];
int predif[MAXN]; //差分
int n,q,l,r,k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    arr[0] = 0;//1base
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        predif[i] = arr[i] - arr[i-1];
    }
    while(q--){
        cin >> l >> r >> k;
        predif[l] += k; //a_l += k, a_l-1 不變
        predif[r+1] -= k; //a_r+1 不變, a_r += k 
    }
    arr[1] = arr[0] + predif[1];
    cout << arr[1];
    for(int i = 2; i <= n; i++){//對差分前綴和
        arr[i] = arr[i-1]+predif[i];
        cout << ' ' <<arr[i];
    }
}