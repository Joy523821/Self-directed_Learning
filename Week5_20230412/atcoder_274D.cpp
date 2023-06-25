#include<bits/stdc++.h>
using namespace std;

int ai[1005]; //上限i=1000

bool can_achieve(vector<int> &vec, int x){ //用來判斷可不可以達成
    unordered_set<int> curset; //計算可能結果
    curset.insert(0);
    int len = vec.size();

    for(int i = 0; i < len; i++){ //一個一個跑要用的數字
        unordered_set<int> nextset; //紀錄結果
        for(auto tmp: curset){
            nextset.insert(tmp + vec[i]); //每個vec[i]可加可減
            nextset.insert(tmp - vec[i]);
        }
        curset = nextset; //吃過去開始下一輪
    }
    return curset.count(x); //x是否存在於curset(可能解)中
}


int main(){
    int n,x,y; //x,y是目標數字
    cin >> n >> x >> y;
    vector<int> vecX,vecY; //x跟Y向的ai

    cin >> ai[1];
    for(int i = 2; i <= n; i++){
        cin >> ai[i];
        (i % 2)? vecX.push_back(ai[i]): vecY.push_back(ai[i]); //奇數+x , 偶數+y
    }

    x -= ai[1]; //第一步只能+x向

    (can_achieve(vecX, x) && can_achieve(vecY, y))? cout << "Yes\n": cout << "No\n";

}

//每走完一次要左右轉，所以奇數次=x方向，偶數次=y方向
//也就是說，除了第一步固定是+x，其他可以是正負
//就是看能不能湊出要的x，y值，所以算總和再一個個扣看會不會遇到就好

/*實際做法:
開一個unordered set，因為插入跟查詢O(1)
再一個und set，把第一個set的每個值加減vec[i]後更新回第一個值
*/
