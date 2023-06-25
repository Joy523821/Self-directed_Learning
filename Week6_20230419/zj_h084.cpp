#include<bits/stdc++.h>
using namespace std;

int n,k;
int height[200010],width[5005]; //每木板高度,海報寬度

bool check(int h){
    int poster = 0, len = 0; //第一章海報的第一單位長
    for(int i = 0; i < n; i++){
        if(height[i] >= h) len++; //可以貼
        else len = 0; //這段不能放海報

        if(len == width[poster]){
            len = 0;
            poster++;
        }

        if(poster == k) return true; //0~k-1都貼完了
    }
    return false;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    for(int i = 0; i < k; i++){
        cin >> width[i];
    }
    //         ^
    //111111111100000
    int l = 1, r = 1e9+7;
    while (l < r) {
        int mid = (l + r) / 2;
        if (!check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l - 1 << '\n';
}