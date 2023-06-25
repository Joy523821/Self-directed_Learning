//迭代快速冪
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
/*原理:假設求2^11次方
  11 = 1011(二進位)
  所以用r=1存答案
  次方n=1011
  表示r = a^1 * a^2 * a^8
  所以用一個值times紀錄a的1,2,4,8..次方
  只要當下n最後一位 = 1表示r含有該次方
  每回合結束r /= 2,所以times需平方
*/
long long fastpow(int a, int n, int MOD){
    long long ret = 1;//回傳
    long long times = a%MOD; //=a^1
    for( ; n > 0; n = n >> 1){//每次跑完n/=2 直到n=0
        printf("ret = %d, n = %d, times = %d\n", ret, n, times);/////////////////////////////
        if(n%2){ //=a * a^n/2 * a^n/2 , 因為 * a^n/2 * a^n/2下面會做所以只要*a
            ret = (ret * times)%MOD; 
        }
        times = (times * times)%MOD;
    }
    printf("ret = %d, n = %d, times = %d\n", ret, n, times);/////////////////////////////
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,n;
    cin >> a >> n;
    cout << fastpow(a, n, MOD);
}