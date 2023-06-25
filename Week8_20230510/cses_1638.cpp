#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1005][1005]; //到dp[x][y]有幾種走法 , -1代表blocked
int MOD = 1e9+7;
/*轉移式 dp[x][y] = dp[x-1][y] + dp[x][y-1]
  邊界條件 x<=0 or y<=0 or dp[x][y]==-1 : return 0
  圖記錄在index 1~n
*/
ll f(int x, int y){ //原本是用遞迴就會TLE 改成迭代
    if(dp[x][y] == -1) return 0;
    if(x<=0 || y<=0) return 0;
    if(dp[x][y] > 0) return dp[x][y];
    return dp[x][y] = (f(x-1, y) + f(x, y-1))%MOD;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(dp, 0, sizeof(dp));
    string tmp;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        for(int j = 1; j <= n; j++) if(tmp[j-1] == '*') dp[j][i] = -1;
    }
    if(dp[1][1] == 0) dp[1][1] = 1; //如果起點被擋就沒了

    for(int j = 1; j <= n; j++){       //順序 1 2
        for(int i = 1; i <= n; i++){   //     3 4
            if(i == 1 && j==1) continue; //不跑起點
            if(dp[i][j] == -1) continue; //不跑阻礙
            ll tmp = 0;
            if(dp[i][j-1] != -1) tmp += dp[i][j-1]; //如果是障礙就是0方法
            if(dp[i-1][j] != -1) tmp += dp[i-1][j];
            dp[i][j] = (tmp)%MOD;
        }
    }
    if(dp[n][n] == -1){ //終點是障礙要輸出1
        cout << "0\n";
        return 0;
    } 
    cout << dp[n][n] << '\n';

    /*輸出整個陣列用的
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << dp[j][i] << " ";
        cout << '\n';
    }*/
}