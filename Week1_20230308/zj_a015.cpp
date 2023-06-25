#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    int A[100][100];
    while(cin >> y >> x){
    
        for(int j = 0;j<y;j++){
            for(int i = 0;i<x;i++){
                cin >> A[i][j];
            }
        }

        for(int i = 0;i<x;i++){
            for(int j = 0;j<y;j++){
                cout << A[i][j]<< " ";
            }
            cout << '\n';
        }      
    }
    
}