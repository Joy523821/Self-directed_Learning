#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*開一個最大連續和conti
  開一個最大部孿旭和disconti
  disconti[i] = max(disconti[i-1]+arr[i], disconti[i-1], conti[i-2]+arr[i])
                    取                    不取            前面是連續 所以隔一格取
*/
const int MAXN = 1e6+7;
int N, arr[MAXN];
ll MAXANS, conti[MAXN], disconti[MAXN];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    conti[0] = arr[0]; //邊界狀態
    for(int i = 1; i < N; i++) conti[i] = max<ll>({conti[i-1], arr[i], conti[i-1]+arr[i]}); //最大連續和:看要1.取前面(自己負) 2.前面負只取自己 3.取前面+自己
    //                                        ^conti是ll 0是int, 需要告訴模板要的是ll

    MAXANS = disconti[2] = arr[0] + arr[2];//邊界狀態
    for(int i = 3; i < N; i++){
        disconti[i] = max<ll>({disconti[i-1]+arr[i], disconti[i-1], conti[i-2]+arr[i]});
        MAXANS = max(disconti[i], MAXANS);
    }

    cout << MAXANS << '\n';
}
//AC code source: https://hackmd.io/@cyk/dp#%E8%A7%A3%E9%A1%8C%E7%AD%96%E7%95%A5