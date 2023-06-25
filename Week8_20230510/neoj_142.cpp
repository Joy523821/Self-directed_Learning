#include<bits/stdc++.h>
using namespace std;
/*定義狀態: dp[i] 前i項中(有取ai)最大值
  邊界狀態: dp[i] = arr[i] ,i=1~k
           dp[ii] = max(arr[ii]+arr[1], ... , arr[ii]+arr[ii-k+1])
  因為值都是正整數，所以每兩個娶的數之間只會隔一或兩格(例如 12345 取 15則 取135>15 所以15不可能是解)
  轉移式: dp[ii] = max(arr[ii]+arr[ii-2k], ... , arr[ii]+arr[ii-k+1]) 至少隔k格 所以可能隔k到2k-1
*/
int t,n,k,arr[2010]; //最大訪問2*k所以可能會訪問到1000*2
int dp[2010];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i<=n; i++) cin >> arr[i];

        for(int i = 1; i <= k; i++) dp[i] = arr[i];//dp[1~k] 初始化
        for(int ii = k+1; ii <= 2*k; ii++){
            for(int j = 1; j <= ii - k ; j++) dp[ii] = max(dp[ii], arr[ii] + arr[j]); //dp[k+1~2K]初始化
        }

        for(int i = 2*k+1; i <= n; i++){
            for(int j = i - 2*k; j <= i - k ; j++){
                dp[i] = max(dp[i] , arr[i]+dp[j]);
            }
        }
        cout << *max_element(dp, dp+n+1) << "\n"; //可能是以任一項作為最後一項
    }
}