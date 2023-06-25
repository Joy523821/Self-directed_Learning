#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
long long a[N]; //存值
map<double, int> mp; //哪個數 , 有幾個

int main(){
    int t,n;
    long long sum,pair; //t case , each case n numbers, sum = array sum
    cin >> t; 
    while(t--){
        sum = 0;
        pair = 0;
        mp.clear();
        double ave = 0;

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            mp[a[i]]++; //沒有時預設0!!!
        }

        ave = (double)sum/n;

        for(int i = 0; i < n; i++){
            if(a[i]==ave){
                pair+=mp[a[i]]-1; //有n個ave,可跟其後的n-1個組合
            }else{
                pair+=mp[ave*2 - a[i]]; //可以組合的
            }
            mp[a[i]]--; //去除檢查過的
        }
        cout << pair << "\n";

    }
}