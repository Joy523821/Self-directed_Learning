#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long tmp;
    long long sum = 0;
    vector<long long> a;
    cin >> n;
    while (n--){
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), less<long long>());
    for(int i = 0; i < a.size()/2; i++){
        sum += a[i];
    }    
    cout << sum << "\n";
}