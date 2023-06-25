#include <bits/stdc++.h>
using namespace std;

vector <int> f(1e5+17, 0);

int query(int a, int count){ //F^count(a)
    if(!(count)) return a; //F^0(a) = a
    return query(f[a], count-1);
}

int main(){
    int n,a,count;
    cin >> n;
    for(int i = 1;i<n+1;i++){ //f1~n
        cin >> f[i];
    }
    cin >> n;
    for(int i = 0;i<n;i++){ //n次
        cin >> a >> count;
        cout << query(a,count) << "\n";
    }
    
}