#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> testtube;
    int temp;

    for(int i = 0;i<n;i++){
        cin >> temp;
        if(temp > 0){
            testtube.push(temp);
        }else{
            if(testtube.empty()){
                cout << "lose light light\n";
                return 0;
            }else if(temp == testtube.top()){
                cout << "lose light light\n";
                return 0;
            }else{
                testtube.pop();
            }
        }
    }

    if(testtube.empty()){
        cout << "weed";
    }else{
        cout << "lose light light\n";
    }
}