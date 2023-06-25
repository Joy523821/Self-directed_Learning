//遞迴快速冪
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll fastpow(int a, int n, int MOD){
    if(n==0) return 1; //a^0=1
    int half = fastpow(a, n/2,  MOD); //一定要打這行存a^(n/2)
    if(n%2){ //奇數次方
        return (half*half*a)%MOD;
    }else{
        return (half*half)%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,n;
    cin >> a >> n;
    cout << fastpow(a, n, MOD);
}