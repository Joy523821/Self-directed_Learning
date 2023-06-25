#include<bits/stdc++.h>
using namespace std;

/*
遇到跟前一個屬性不一樣的直接拿走
遇到屬性一樣的比大小決定要不要放棄之前的
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k; //k好像不會用到ㄟ
    int SW[n][2] = {0}; //第一項是S,第二項是W
    int curS = 0,lastTake; //lasttake紀錄上次拿了甚麼
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++){
            cin >> SW[i][j];
        }
    }

    curS += SW[0][0]; //先拿第一個
    lastTake = SW[0][0];
    for(int i = 1; i < n; i++){
        if(SW[i][1] != SW[i-1][1]){
            curS += SW[i][0];
            lastTake = SW[i][0];
        }else if(SW[i][0] > lastTake){
            curS -= lastTake; //退貨
            curS += SW[i][0];
            lastTake = SW[i][0];
        }
    }

    cout << curS << "\n";

}