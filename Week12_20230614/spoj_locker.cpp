#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
/*白話文題目:
 把n寫成a1+a2+..+an, [int ai > 0]
 求a1*a2*..*an最大值
 可以發現, 效力:拆成一堆3 > 一堆2 > 其他任何數字
 例如 n = 12
 2^6 = 64;
 3^4 = 81;
 其餘任何組合皆 < 64;
*/
ll fastpow_three(ll n){ //只會算3^n
    ll ret = 1;
    ll fac = 3;
    for(; n > 0; n >>= 1){
        if(n%2) ret = (ret*fac)%MOD;
        fac = (fac*fac)%MOD;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t,n; //MAXN = 1e12;
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1) cout << 1 << '\n'; //n = 1, ret = 1
        else if(n==2) cout << 2 << '\n'; //n = 2, ret = 2
        else if(n==3) cout << 3 << '\n'; //n = 3, ret = 3
        else if(n%3 == 0) cout << fastpow_three(n/3) << '\n';//n = 3k, ret = 3^k
        else if(n%3 == 1) cout << (4 * fastpow_three(n/3 - 1))%MOD << '\n';//n = 3k+1, ret = 4 * 3^(k-1)
        else if(n%3 == 2) cout << (2 * fastpow_three(n/3))%MOD << '\n';//n = 3k+2, ret = 2 * 3^k
    }
}
