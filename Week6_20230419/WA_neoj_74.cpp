#include<bits/stdc++.h> //-------------unsolved------------
using namespace std;
//neoj74_萬里長城介紹

/*
    短-長-cur-next
    cur < next:
        count++
        長短互換
    cur > next:
        放棄cur
        換next
    長開頭
    短結尾就count--
*/
unsigned int stoneHeight[1000010]; //石頭高度

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i< n; i++){
            cin >> stoneHeight[i];
        }
        int count = 1, lastTake = stoneHeight[0]; //先拿第一個
        bool wantHigh = false; //true是要高的 false是要低的
        for(int i = 1; i < n; i++){
            if(!((stoneHeight[i] > lastTake)^wantHigh)){ //符合要求 要高/更高 要低/更低
                count++;
                lastTake = stoneHeight[i];
                wantHigh ? wantHigh = false : wantHigh = true; //翻轉高低要求
            }else{
                lastTake = stoneHeight[i];
            }
        }
        if(wantHigh) count --; //收在低的話不要最後一顆
        cout << count << "\n";
    }
}