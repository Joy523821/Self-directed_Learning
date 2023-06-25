#include<bits/stdc++.h>
using namespace std;
/*
    距離最大值為n
    意即可以用範圍長2n+1的滅火器來覆蓋全部
*/

int treePos[100005];
int t,n,k;

bool check(int r){ //滅火器半徑長
    int covered = 0;
    int used = 0;
    for(int i = 0; i < n; i++){
        if(treePos[i] > covered){
            used += 1;
            covered = treePos[i] + 2*r;
        }
        if(used > k) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //沒優化會TLE
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> treePos[i];
        sort(treePos, treePos+n, less<int>());

        int l = 0, r = 1e9+7;
        while(l < r){
            int mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << "\n";
    }
}