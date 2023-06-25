#include<bits/stdc++.h>
using namespace std;
/*
概念:因為第i格高j的前一個必定是從i-1格的j+1, j, j-1走過來的
     故只要每前進一格,就做一次dp,如果高度已經指定了就做那個高度的就好(如此一來同一格其他高度的可能就是'0')
     反之,若未指定高度,就把那一格全部每個高度全部dp一遍

定義狀態 dp[i][j] : 走到第i格,高度為j有幾種走法
轉移式   dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1] 
        未指定高度時j = 1~m
邊界條件 第一格指定高度a則 dp[0][a] = 1 , 其餘0
        未指定高度則 dp[0][ALL] = 1  
*/
int dp[100005][105];
const int MOD = 1e9+7; //1e9+7
int n,m,a; //a0 ~ an-1,    MAX_Height = m

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m; //0_base
    memset(dp, 0, sizeof(dp));//setup
    cin >> a; //a0
    if(a==0) for(int height = 1; height <= m ; height++) dp[0][height] = 1;
    else dp[0][a] = 1;

    for(int i = 1; i < n; i++){ //a1 ~ an-1
        cin >> a;
        if(a != 0){
            dp[i][a] += dp[i-1][a-1];
            dp[i][a] %= MOD;
            dp[i][a] += dp[i-1][a];
            dp[i][a] %= MOD;
            dp[i][a] += dp[i-1][a+1];
            dp[i][a] %= MOD;
        } 
        else{
            for(int height = 1; height <= m; height++){
                dp[i][height] += dp[i-1][height-1];
                dp[i][height] %= MOD;
                dp[i][height] += dp[i-1][height];
                dp[i][height] %= MOD;
                dp[i][height] += dp[i-1][height+1];
                dp[i][height] %= MOD;
            }
        }
    }

    long long ans = 0;
    for(int height = 1; height <= m; height ++){
        ans += dp[n-1][height];
        ans %= MOD;
    }
    cout << ans << '\n';
}