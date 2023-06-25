#include <bits/stdc++.h>
using namespace std;
#define abc ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  //EOF不能用

int GCD(int a,int b){
    if(a%b == 0) return b;
    return GCD(b, a%b);
}

int main(){
    int a,b;
    while(cin >> a>>b){
        if(b>a) swap(a,b);
        cout << GCD(a,b) << "\n";
    }
}