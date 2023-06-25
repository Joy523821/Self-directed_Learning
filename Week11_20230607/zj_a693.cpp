#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;

int arr[MAXN];
int presum[MAXN];
int n,m,l,r;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> m){
        presum[0] = 0;
        for(int i = 1; i <= n; i++){//1base
            cin >> arr[i];
            presum[i] = presum[i-1] + arr[i];
        }
        while(m--){
            cin >> l >> r;
            cout << presum[r] - presum[l-1] << '\n';
        }
    }
}
