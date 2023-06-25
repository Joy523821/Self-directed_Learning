#include<bits/stdc++.h>
using namespace std;

int main(){
    int times; //幾行
    cin >> times;
    while(times--){
        int n; //n台車
        cin >> n;
        int current = 1; //右邊最前面是誰
        stack<int> middle_station;
        queue<int> left; //要車的順序:先進先出
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            left.push(temp);
        }

        while (current <= n+1 && !left.empty()){ //右邊還有車或左邊還要
            if(middle_station.empty() || middle_station.top() != left.front()){ //車站不能開到右邊就先左到車站
                middle_station.push(current);
                current++;
            }else if(middle_station.top() == left.front()){ //車站開到右邊
                middle_station.pop();
                left.pop();
            }
        }

        if (middle_station.empty()) { //車都開完了嗎?
            cout << "Yes\n"; 
        }else{
            cout << "No\n";
        
        }
    }
}