#include<bits/stdc++.h>
using namespace std;

const int Mod = 1e9+7;
/*
    a^11 十進位 = a^1011 二進位
    所以用current計a^1,a^2,a^4...
    如果n%2==1就表示含current
    然後current平方
    n減半
*/

int fastpow_it(int a, int n){
    long long current = a;
    long long ans = 1;
    while(n>0){
        if(n%2) ans = ans*current % Mod;
        current = current*current % Mod;
        n >>= 1;
    }
    return ans;
}

int main(){
    int a,n;
    cin >> a >> n;
    cout << fastpow_it(a,n);
}

