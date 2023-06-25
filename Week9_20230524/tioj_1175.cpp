#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; //序列長度
    int a; //an
    vector<int> LIS; //dp
    cin >> n;
    while(n--){
        cin >> a;
        if(LIS.empty()){
            LIS.push_back(a);
        }else if (LIS.back() < a){
            LIS.push_back(a);
        }else{
            auto pt = lower_bound(LIS.begin(), LIS.end(), a);
            *pt = a;
        }
    }
    cout << LIS.size() << '\n';
}