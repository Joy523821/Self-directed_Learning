#include <bits/stdc++.h>
using namespace std;

int main(){ ////////////////////////////////////要開long long 喔喔喔
    long long n,sum = 0,temp;
    while(cin >> n){
        sum = 0;
        priority_queue<long long, vector<long long>, greater<long long> > body;

        while (n--){
            cin >> temp;
            body.push(temp);
        }

        while (body.size() > 1){ //切割(的倒著)
            temp = body.top();
            body.pop();
            temp += body.top();
            body.pop();
            sum += temp;
            body.push(temp);
        }

        cout << sum << "\n";

    } 
}