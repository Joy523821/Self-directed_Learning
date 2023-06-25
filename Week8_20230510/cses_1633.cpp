#include<bits/stdc++.h>
using namespace std;
/*初始狀態:dp[1] = 1, dp[0 and -n] = 0
  轉移式:dp[n] = dp[n-1]+..+dp[n-6]
*/

long long dp[1000007]; //總和為n點有dp[n]種可能(mod 1e9+7)
int MOD = 1e9+7;

long long f(int n){
    if(n < 0) return 0;
    if(dp[n] != 0) return dp[n];
    long long tmp;
    tmp = (f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6))%MOD;
    return dp[n] = tmp;
}

int main(){
    memset(dp,0,1000007);
    dp[0] = 1;

    int n;
    cin >> n;
    cout << f(n) << "\n";
}