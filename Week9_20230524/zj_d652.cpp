#include<bits/stdc++.h>
using namespace std;
/*定義狀態 dp[i][j] 把i~j範圍吸收光所造成破壞的最小值
  轉移式 dp[i][j] = min(dp[i][k] + dp[k][j] + v[i]*v[k]*v[j],  k = from i+1 to j-1, j-i >= 3適用(隔兩個以上))
         也就是「先把ik之間和kj之間分別吸收完 + i-k-j吸收」的代價，在k所有情況中最小的
  邊界 j-i = 0 or 1 時 dp = 0
      j-i = 2 時 dp = j*mid*i
*/
const int INF = -1;
int dp[55][55];
int val[55];
int n;

int find(int i, int j){
	//cout << i << ' ' << j << ' ' <<dp[i][j] << '\n';
	if(dp[i][j] != INF) return dp[i][j];
	for(int k = i+1; k <= j-1; k++){ //i-..-k-..-j
		dp[i][j] = min(dp[i][j], find(i,k) + find(k,j) + val[i]*val[k]*val[j]);
		if(dp[i][j] == -1) dp[i][j] = find(i,k) + find(k,j) + val[i]*val[k]*val[j];
	}
	return dp[i][j];
}

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }

	memset(dp, INF, sizeof(dp));
    for(int i = 1; i <= n; i++){
		dp[i][i] = 0;
		dp[i][i+1] = 0;
		dp[i][i+2] = val[i]*val[i+1]*val[i+2];
    }
/*	for(int i = 1; i <= n-3; i++){ //n-2. n-1. n初始條件算過了
		for(int j = i+3; j <= n; j++){ //j = i, i+1, i+2初始條件算過了
			for(int k = i+1; k <= j-1; k++){ //i-..-k-..-j
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + val[i]*val[k]*val[j]);
				
			}
			cout << i << ' ' << j << ' ' <<dp[i][j] << '\n'; 
		}
	} */

	cout << find(1, n) << '\n';
}