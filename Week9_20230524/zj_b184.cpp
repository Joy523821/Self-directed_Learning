//背包問題
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m = 100; //有幾個物品 背包容量
    while(cin >> n){ //EOF
        long long dp[n+1][m+1]; //前i物品，背包大小j的話最多可以拿多少價值的東西，範圍會是0~n 0~m

        for(int i = 0; i <= m; i++) dp[0][i] = 0; //邊界狀態: 都不拿的話背包再大也是0

        int w,p; //重量 價值
        for(int i= 1; i <= n; i++){
            cin >> w >> p;
            for(int j = 0; j <= m; j++){
                if(j < w){//物品比背包重放不下
                    dp[i][j] = dp[i-1][j];
                }else{//比比看拿不拿
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + p);
                }
            }
        }

        cout << dp[n][m] << '\n';
    }
}