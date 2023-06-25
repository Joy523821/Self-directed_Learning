#include<bits/stdc++.h>
using namespace std;
#define cool ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/*滾動dp減少記憶體用量
  curr[i] 存 原本dp[i][j]
  prev[i] 存 dp[i-1][j]
  所以初始狀態 i = 0 or j = 0,  curr[j] = 0
  轉移式 a[i] == b[j], curr[j] = prev[j-1] + 1 (LCS[i][j] = LCS[i-1][j-1]+1)
        否則,          curr[j] = max(curr[j-1], prev[j]), 就i-1,j 跟i,j-1的轉移
  所求=完成的curr最後一項
*/
const int MAXN = 1e5+5;
int curr[MAXN]; //dp[i][*]
int pre[MAXN]; //dp[i-1][*] //哭喔prev是保留字啦
int A[MAXN];
int B[MAXN];

int main(){cool
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1; i <= n; i++) cin >> B[i];
    
    memset(pre, 0, sizeof(pre));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i==0 || j==0) curr[j] = 0;
            else if(A[i] == B[j]) curr[j] = pre[j-1] + 1;
            else curr[j] = max(curr[j-1], pre[j]);
        }
        for(int it = 0; it <= n; it++){
            pre[it] = curr[it]; //curr變成prev
        }
    }
    
    cout << curr[n] << '\n';

}