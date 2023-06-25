#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mod = 1e9+7;

int fastpow(int a, int n){ //0^0 = 1, 0^n = 0
    if(n == 0) return 1;
    if(n == 1) return a;
    ll half = fastpow(a, n>>1);
    ll full = half*half % Mod; //對於奇數次方 = a^n-1
    if(n%2) return full*a %Mod;
    return full;
}

int main(){
    int a,b,n;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << fastpow(a, b) << "\n";
    }
}