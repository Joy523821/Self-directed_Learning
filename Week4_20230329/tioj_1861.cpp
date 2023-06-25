#include <bits/stdc++.h>
using namespace std;
/*把一塊分成a,b兩塊代價a+b
  從一塊完整的拆成n塊
  和「從n塊拼回一塊，合併a,b代價a+b」等價
  所以開一個pq來紀錄每塊值，每次選最小的合併直到剩下一塊
  此時代價即最小
*/
int main(){ //變數要開long long 喔
    long long n,sum = 0,temp;//塊數, 代價
    while(cin >> n){ //本題為EOF
        sum = 0;
        priority_queue<long long, vector<long long>, greater<long long> > body; //值從小到大的pq

        while (n--){
            cin >> temp;
            body.push(temp);
        }

        while (body.size() > 1){ //切割(的倒著) = 合併
            temp = body.top(); //值最小的塊
            body.pop();
            temp += body.top(); //值次小的塊
            body.pop();
            sum += temp;
            body.push(temp); //合併之後產生新的塊
        }

        cout << sum << "\n";

    } 
}
