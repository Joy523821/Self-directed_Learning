#include<bits/stdc++.h>
using namespace std;

int pos[50010];
int N,K;

bool check(int r){
    int cover = 0;//cover以前的都覆蓋到了
    int used = 0;//用了幾個基地台
    for(int i = 0; i < N; i++){
        if(pos[i] > cover){
            used ++;
            cover = pos[i] + r; 
        }
    }
    if(used > K) return false;
    return true;
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> pos[i];
    sort(pos, pos+N, less<int>());

    //00000111111
    //     ^
    int l = 1, r = 1e9+7;
    while (l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l;
    
}