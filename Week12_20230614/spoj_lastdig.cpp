#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fastpow(int a, int n, int MOD){
    ll ret = 1;
    ll factor = a%MOD;
    for(; n > 0; n>>=1){ // n/=2;
        if(n%2){
            ret = (ret*factor)%MOD;
        }
        factor = (factor*factor)%MOD;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,a,n;
    cin >> t;
    while(t--){
        cin >> a >> n;
        cout << fastpow(a, n, 10) << '\n'; //最後一位數字 = ret%10;
    }
}