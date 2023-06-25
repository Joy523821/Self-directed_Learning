#include<bits/stdc++.h>
using namespace std;

vector<int> fib(5,-1); //費式數列 O(n)解
int MAXN = 40;

int f(int n){
    if (fib[n] > 0) return fib[n]; //dp
    return fib[n] = f(n-1) + f(n-2);
}

int main(){
    fib[0] = 1;//邊界條件
    fib[1] = 1;
    fib.resize(MAXN);

    for(int i = 1; i < MAXN; i++) cout << "f(" << i << ") = " << f(i) << endl;
}