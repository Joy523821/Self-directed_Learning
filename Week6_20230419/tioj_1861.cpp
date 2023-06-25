#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n){
        priority_queue<long long, vector<long long>, greater<long long> > bodies; //小到大
        long long tmp;
        while(n--){
            cin >> tmp;
            bodies.push(tmp);
        }
        long long value=0,a,b;
        while(bodies.size() > 1){
            a = bodies.top();
            bodies.pop();
            b = bodies.top();
            bodies.pop();
            value += a + b;
            bodies.push(a+b);
        }
        cout << value << "\n";
    }
}