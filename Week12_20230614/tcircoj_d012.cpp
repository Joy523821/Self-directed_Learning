#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fastpow(int a, int n, int MOD){
    ll ret = 1;
    ll fac = a%MOD;
    for(; n > 0; n >>=1){
        if(n%2) ret = (ret*fac)%MOD;
        fac = (fac*fac)%MOD;
    }
    return ret;
}

int main(){
    int a,b,p;
    cin >> a >> b >> p;
    cout << fastpow(a, b, p) << '\n';
}