#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;

int arr[MAXN];
long long presum[MAXN];//前綴和
int n,q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    presum[0] = 0;
    for(int i = 1; i <= n; i++){//1base
        cin >> arr[i];
        presum[i] = arr[i] + presum[i-1];
    }
    int l,r;
    while(q--){
        cin >> l >> r;
        cout << presum[r] - presum[l-1] << '\n';
    }
}