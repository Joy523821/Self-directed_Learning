#include<bits/stdc++.h>
using namespace std;

int arr[100005],n,arrtmp[100005];

void goodArray(int left, int right){
    if(right - left <= 1) return;
    int mid = left + (right - left >> 1);
    int ind = left;
    for(int i = left; i <= right; i++) arrtmp[i] = arr[i];
    for(int i = left; i <= right; i += 2) arr[ind++] = arrtmp[i];
    for(int i = left+1; i <= right; i += 2) arr[ind++] = arrtmp[i];
/*
    cout << left << " to " <<  right << "   ";
for(int i = 0; i < n; i++) cout << arr[i] << " ";///////////////////////////
    cout << "\n";
*/
    goodArray(left, mid);
    goodArray(mid+1, right);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) arr[i] = i+1;
/*
for(int i = 0; i < n; i++) cout << arr[i] << " ";////////////////
    cout << "\n";
*/
    goodArray(0, n-1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}
/*
    原本數列 12345678 <- 全部等差
    把第奇數項放前面偶數放後面 1357|2468
    可以發現 每一塊(前/後) 都是全部等差
    但是如果從其中一邊取一 另一編取兩個
    則不可能是等差 數列
    所以只要一直切半，直到每一區域都只剩2塊以下，就不可能有等差

    left9 left10 left11 left12 left13 left14 left15 
    12    9      13     10     14     11     15
*/