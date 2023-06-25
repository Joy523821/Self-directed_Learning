//source:https://codeforces.com/group/P89l5d9Gn0/contest/382103/problem/A
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+7;
/*因為給l=1,r=4,d=d的意思是
  a1    a2    a3    a4    a5
  a1+d  a2+2d a3+3d a4+4d a5
  一次差分=[d, d, d, d, -4d]
  對前四項可發現
  二次差分=[d, 0, 0, 0, -d]
  所以只要在二次diff第l項+d 第r+1項-d
  一次diff第r+1項-(r-l+1)d
  然後連續前綴和兩次就好了
*/
long long int arr[MAXN];
long long int predif[MAXN]={}; //1_base
long long int double_predif[MAXN]={};
int n,m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    long long int l,r,d;
    while(m--){ //差分區
        cin >> l >> r >> d;
        double_predif[l] += d;
        double_predif[r+1] -= d;
        predif[r+1] -= (r-l+1)*d;
    }

    long long int double_predif_sum = 0, predif_sum = 0;//用變數存就可以跑一圈跑好兩層前綴和
    for(int i = 1; i <= n; i++){
        double_predif_sum += double_predif[i];
        predif[i] += double_predif_sum;
        predif_sum += predif[i];
        cout << arr[i] + predif_sum << ' ';
    }
    cout << '\n';
}

