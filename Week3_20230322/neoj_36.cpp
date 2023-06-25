#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,temp,choice;
    stack<int> a;
    cin >> n;
    for(int i = 0; i<n ; i++){
        cin >> choice;
        if(choice == 1){
            cin >> temp;
            a.push(temp);
        }else{
            if(a.empty()){
                cout << "empty!\n";
            }else{
                cout << a.top() << "\n";
                a.pop();
            }
        }
    }
}