#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
int arr[MAXN],arrtmp[MAXN];

long long count(int left, int right){
    if(left + 1 == right) return 0; //長度剩1
    int mid = left + (right - left >> 1);
    long long cnt = count(left, mid) + count(mid, right);
    int L, R = mid;
    for(L=left; L < mid; L++){
        while(R<right && arr[R] < arr[L]) R++;
        cnt += R-mid;
    }
    L = left, R = mid;
    int K = left;
    while(L < mid || R < right){ //合併到兩邊都用完為止
        if(L < mid && (R >= right || arr[L] <= arr[R])) //左邊還有剩 而且 右邊用完或是左邊小於右邊
            arrtmp[K++] = arr[L++]; //選左邊
        else
            arrtmp[K++] = arr[R++]; //選右邊
    }
    for(int it = left; it < right; it++) //合併
        arr[it] = arrtmp[it];
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,cases = 0;
    cin >> n;
    while(n != 0){
        cases++;    
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << "Case #"<< cases << ": " << count(0,n) << "\n";
        cin >> n;
    }
}
