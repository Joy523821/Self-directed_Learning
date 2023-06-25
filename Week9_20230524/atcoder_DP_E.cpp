//因為二維DP會MLE所以要滾動一維dp
//背包問題
#include <bits/stdc++.h>
using namespace std;
/*通常背包問題的解法是
  dp[w] 存容量w時的最大價值
  在for n中跑並更新每個dp[w]的最大值(滾動DP)
  可是這題的w MAX = 1e9, for迴圈會直接TLE, 宣告會直接CE
  觀察發現此題總價值i MAX = n MAX * v MAX = 1e5 小很多 
  所以用換位DP, dp[i]代表拿取總價值i所需最小重量, 只需開1e5的空間,for迴圈迭代次數也大幅減少
  邊界條件 dp[0] = 0, dp[非0] = -1 (用-1來標記表示還沒有方法可以拿到總價值i)
  轉移式 當下一個物品有值重w, 價值p時
  1. dp[i-p] = -1 無法達成所以continue;
  2. dp[i-p] >= 0 如果dp[i]不存在, dp[i] = dp[i-p] + w
  3. dp[i-p] >= 0 如果dp[i]存在, dp[i] = min(dp[i], dp[i-p] + w)
  *因為是滾動dp,加上取值永遠只會訪問到index比自己小的,所以須從最大值往小遍歷
*/
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); //io優化
    int n,m; //有幾個物品 背包容量
    cin >> n >> m;
    long long dp[100005]; //MAXN*MAXp=MAXi=1e5
    memset(dp, -1, sizeof(dp));//使做不到的永遠>m //乖乖用sizeof 用100005會炸
    dp[0] = 0;
    int w,p;
    for(int i = 1;i <= n; i++){//一邊輸入一邊DP
        cin >> w >> p;
        for(int j = 100000; j >= p; j--){ //從最大總價值跑回來, j<p則index<0會RE
            if(dp[j-p] != -1){
                if(dp[j] != -1) dp[j] = min(dp[j], dp[j-p] + w);
                else dp[j] = dp[j-p] + w;
                //cout << j << ' ' << dp[j] << ' ';測試輸出
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
