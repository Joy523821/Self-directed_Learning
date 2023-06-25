#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int nhalf = (s.length())/2;
    int echo = 1;
    int j = s.length()-1;
    for(int i = 0;i<nhalf;i++){
        if(s[i] != s[j-i]){
            echo = 0;
            break;
        }
    }
    
    echo? cout << "yes" : cout << "no";
}