#include<bits/stdc++.h>
using namespace std;
/*定義狀態: dp[i] 前i項中(有取ai)最大值
  邊界狀態: dp[1] = arr[1]
           dp[2] = arr[2]
           dp[3] = arr[1] + arr[3]
  因為值都是正整數，所以每兩個娶的數之間只會隔一或兩格(例如 12345 取 15則 取135>15 所以15不可能是解)
  轉移式: dp[i] = max(dp[i-2] ,dp[i-3]) + arr[i] 隔一格，隔兩格
*/
int t,n,arr[100005];
int dp[100005];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i<=n; i++) cin >> arr[i];
        memset(dp, 0, sizeof(dp));

        dp[1] = arr[1], dp[2] = arr[2], dp[3] = arr[1] + arr[3];
        for(int i = 4; i <= n; i++){
            dp[i] = max(dp[i-2] , dp[i-3]) + arr[i];
        }
        cout << max(dp[n], dp[n-1]) << "\n"; //可能是以an, an-1作為最後一項
    }
}