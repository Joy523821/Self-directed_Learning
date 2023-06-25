#include<bits/stdc++.h>
using namespace std;

unordered_map<long long,long long> f; //存f[n]


long long find(long long n){ //func:long long(MAXN = 1e18)
    if(f[n]) return f[n]; //f[n]有解,直接回傳
    f[n/2] = find(n/2);
    f[n/3] = find(n/3);
    return f[n/2] + f[n/3];
}

int main(){
    f[0] = 1;
    long long n;
    cin >> n;
    cout << find(n);
}