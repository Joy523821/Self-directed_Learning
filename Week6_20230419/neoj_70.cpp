#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n,tmp,a,b;
        long long sum=0;
        cin >> n;
        priority_queue<long long , vector<long long>, greater<long long> > pq; //小到大
        while (n--){
            cin >> tmp;
            pq.push(tmp);
        }
        while(pq.size() > 1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            sum += a + b;
            pq.push(a+b);
        }
        cout << sum << '\n';
    }
}