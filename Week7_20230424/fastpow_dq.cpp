#include<bits/stdc++.h>
using namespace std;

const int Mod = 1e9+7;

long long fastpow(int a, int n){
    if(n == 1) return a;
    long long half = fastpow(a, n/2);
    long long full = half*half % Mod;
    if(n % 2) return full*a % Mod;
    return full;
}

int main(){
    int a, n;
    cin >> a >> n;
    cout << fastpow(a, n);
}