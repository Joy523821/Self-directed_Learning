#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*定義狀態: dp[i][l][r] 長度i 左邊是l色 右邊是r色 (R G B = 1 2 3)
  邊界條件: 長度1的R G B , dp都是1
           長度2的RR RG RB GR GG BR BB合法 dp=1 || GB BG不合法dp=0
  轉移式: R接RGB    dp[i][頭][R] = dp[i-1][頭][R] + ..[G] + ..[B]
         G接RG     dp[i][頭][G] = dp[i-1][頭][R] + ..[G]
         B接RB     dp[i][頭][R] = dp[i-1][頭][R] + ..[B]
  輸出: dp[i] = dp[i](RR RG RB GR GG BR BB)的和
*/
ll dp[100005][3][3]; //長度 頭顏色 尾顏色
int t; //有幾筆測試
const int MOD = 1e6 + 7;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    dp[1][0][0] = dp[1][1][1] = dp[1][2][2] = 1; //R G B
    dp[2][0][0] = dp[2][0][1] = dp[2][0][2] = 1; //RR RG RB
    dp[2][1][0] = dp[2][1][1] = dp[2][2][0] = dp[2][2][2] = 1; //GR GG BR BB
    dp[2][2][1] = dp[2][1][2] = 0; //BG GB

    for(int i = 3; i <= 100005; i++){
        for(int headColor = 0; headColor < 3; headColor++){
            dp[i][headColor][0] = (dp[i-1][headColor][0] + dp[i-1][headColor][1] + dp[i-1][headColor][2])%MOD; //R接RGB
            dp[i][headColor][1] = (dp[i-1][headColor][0] + dp[i-1][headColor][1])%MOD; //G接RG
            dp[i][headColor][2] = (dp[i-1][headColor][0] + dp[i-1][headColor][2])%MOD; //B接RB
        }
    }

    cin >> t;
    while(t--){
        int a;cin>>a; //dp[i](RR RG RB GR GG BR BB)的和
        cout<<(dp[a][0][0]+dp[a][0][1]+dp[a][0][2]+dp[a][1][0]+dp[a][1][1]+dp[a][2][0]+dp[a][2][2])%MOD<<"\n"; 
    }
}

//ACcode source: https://peienwu.com/sprout7-2/