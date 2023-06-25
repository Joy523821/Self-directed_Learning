#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    費馬小定理: a^(p-1) = 1(mod p)
    如果 n = b^c / p
    可以發現 a^(b^c) mod p = a^(b^c mod p-1) * (a^(p-1))^n = ans * 1^n = ans
*/
const int Mod = 1e9+7;

int fastfastpow(int a, int n,int m){ //0^0 = 1, 0^n = 0
    if(n == 0) return 1;
    if(n == 1) return a;
    ll half = fastfastpow(a, n>>1, m);
    ll full = half*half % m; //對於奇數次方 = a^n-1
    if(n%2) return full*a % m;
    return full;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, c;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        ll tmp = fastfastpow(b,c,Mod-1);
        cout << fastfastpow(a,tmp,Mod) << '\n';
    }
}