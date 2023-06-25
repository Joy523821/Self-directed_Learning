#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, choice,temp;
    priority_queue<int, vector<int>, greater<int> > pq;
    cin >> n;
    while (n--){
        cin >> choice;
        if(choice == 1){
            cin >> temp;
            pq.push(temp);
        }else if(choice == 2){
            if(pq.empty()){
                cout << "empty!\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    
}