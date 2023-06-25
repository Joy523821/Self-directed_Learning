#include<bits/stdc++.h>
using namespace std;

long long dp[505][505]; //dp[l][r] l~r區間
int val[505]; //存值
int n;

long long gcd(int a, int b){
    if(b > a) return gcd(b, a);
    if(a==1 && b==0) return INT64_MIN/100;
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> val[i];
    memset(dp, 0, sizeof(dp));
    for(int l = 1; l <= n; l++) for(int r = l; r <= n; r++) dp[l][r] = INT64_MIN/100;
    for(int l = 1; l+1 <= n; l++) dp[l][l+1] = gcd(val[l], val[l+1]);
    for(int l = 1; l+2 <= n; l++) dp[l][l+2] = gcd(val[l], val[l+1]) + gcd(val[l+1], val[l+2]);
    for(int d = 2; d <= n; d++){
        for(int l = 1; l+d <= n; l++){ //////////////////////////////////////////////////r = l+d
            dp[l][l+d] = max(dp[l][l+d], dp[l][l+1]+dp[l+2][l+d]);
            dp[l][l+d] = max(dp[l][l+d], dp[l][l+2]+dp[l+3][l+d]);
            dp[l][l+d] = max(dp[l][l+d], dp[l+1][l+d-1] + gcd(val[l], val[l+d]));
           // cout << l << '-' << l+d;//////////////////////////////////////////////// 
            for(int k = l+1; k <= l+d-1; k++){
                dp[l][l+d] = max(dp[l][l+d], dp[l+1][k-1] + dp[k+1][l+d-1] + gcd(val[l],val[k]) + gcd(val[k],val[l+d]));
            }
           // cout << '=' << dp[l][l+d] << '\n';///////////////////////
        }
    }

    if(dp[1][n] <= INT64_MIN/128) cout << "-1\n";
    else cout << dp[1][n] << '\n';
}