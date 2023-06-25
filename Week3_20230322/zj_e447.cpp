#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,choice,temp;
    cin >> n;
    queue<int> q;
    while(n--){
        cin >> choice;
        switch(choice){
            case 1:
                cin >> temp;
                q.push(temp);
                break;
            case 2:
                if(q.empty()){
                    cout << "-1\n";
                }else{
                    cout << q.front()<<"\n";
                }
                break;
            case 3:
                if(!q.empty()) q.pop();
        }
    }
}