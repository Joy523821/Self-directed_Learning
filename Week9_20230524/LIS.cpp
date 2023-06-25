//Longest Increasing Subsequence最長遞增子序列
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; //數列長度
    int a; //每一項
    cin >> n;
    vector<int> LIS; //dp用
    while(n--){
        cin >> a;
        if(LIS.empty()){
            LIS.push_back(a);
        }else if(LIS.back() < a){ //新加入的是數字比結尾大就加到最後
            LIS.push_back(a);
        }else{
            auto pt = lower_bound(LIS.begin(), LIS.end(), a); //找到第一個不小於a值的「位址」
            *pt = a; //取代
        }

        cout << "LIS:";
        for(auto it = LIS.begin(); it != LIS.end(); ++it){ //跑過整個vector
            cout << *it << ' ';
        }
        cout << '\n';
    }

}