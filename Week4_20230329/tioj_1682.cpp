#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        vector<int> vec(n);
        for(int i = 0; i < n; i++) cin >> vec[i];

        sort(vec.begin(), vec.end(), less<int>());

        

        for(auto it : vec){
            cout << it;
            if(it != vec.back()) cout << " ";
        }
        cout << "\n";
    }
    
}