#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,temp;
    cin >> n;
    stack<int> bulls; //其實只是為了從尾巴開始判斷
    while(n--){
        cin >> temp;
        bulls.push(temp);
    }
    stack<int> cansee; //可以看到多少(尾巴開始判定)
    int temp2 = 0,bullleft = bulls.top(); //左邊牛身高
    cansee.push(0);
    bulls.pop();

    while(!bulls.empty()){
        if(bulls.top() < bullleft){ //左<右,可見1
            cansee.push(1);
            temp2 = 1;
        }else if(bulls.top() == bullleft){ //左==右,可見1,但更左邊牛不一定ex 4 3 3 2
            cansee.push(1);
            temp2 += 1;
        }else{//左>右,可見=右邊+1
            temp2 += 1;
            cansee.push(temp2);
        }
        
        bullleft = bulls.top();//換下一個
        bulls.pop();
    }
    
    while (!cansee.empty()){
        cout << cansee.top()<<"\n";
        cansee.pop();
    }
    
}