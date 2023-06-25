#include<bits/stdc++.h>
using namespace std;

int step(int n){
    int i = 0;
    int k = n;
    while(1){
        i++;
        if(k==1) return i;
        if(k%2){k = 3*k + 1;}
        else{k /= 2;}
    }
}

int main(){
    int i,j,maxstep,a,b;
    while(cin >> i >> j){
        if(i<j){a=i;b=j;}
        else{a=j;b=i;}
        maxstep = 0;
        for(int t = a;t<=b;t++){
            maxstep = max(maxstep,step(t));
        }
        cout << i << " "<< j << " "<< maxstep<<"\n";
    }
}