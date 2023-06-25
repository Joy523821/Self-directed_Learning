//因為二維DP會MLE所以要滾動一維dp
//背包問題
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m; //有幾個物品 背包容量
    cin >> n >> m;
    //定義dp[i]為 裝價值i所需最小容量
    //邊界dp[0] = 0, dp[!=0]= 2^31-1
    //從大到小覆蓋
    //轉移式dp[j] = min(dp[j], dp[j-p] + w);
                      //原本   在價值i-p時拿了這個東西
    long long dp[100005]; //MAXN*MAXp
    memset(dp, -1, sizeof(dp));//使做不到的永遠>m //乖乖用sizeof 用100005會炸
    dp[0] = 0;
    int w,p;
    for(int i = 1;i <= n; i++){
        cin >> w >> p;
        for(int j = 100000; j >= p; j--){ //從最大總價值跑回來
            if(dp[j-p] != -1){
                if(dp[j] != -1) dp[j] = min(dp[j], dp[j-p] + w);
                else dp[j] = dp[j-p] + w;
                //cout << j << ' ' << dp[j] << ' ';
            }
        }
    }
    for(int i = 100000; i > -1; i--){ //找出容量小於m的最大value
        if(dp[i] <= m && dp[i] != -1){
            cout << i << '\n';
            break;
        }
    }
}