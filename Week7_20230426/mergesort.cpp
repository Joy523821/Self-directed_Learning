#include<bits/stdc++.h>
using namespace std;

int n,arr[1000010],arrtmp[1000010];

void mergesort(int left, int right){ //排序[left, right)
    if (left + 1 == right) return; //長度等於一終止遞迴
    int mid = left + (right - left >> 1);
    mergesort(left, mid); //拆成小問題
    mergesort(mid, right);
    int L = left, R = mid, K = left; //開始合併(左半指標、右半指標、成品指標)
    while(L < mid || R < right){ //合併到兩邊都用完為止
        if(L < mid && (R >= right || arr[L] <= arr[R])) //左邊還有剩 而且 右邊用完或是左邊小於右邊
            arrtmp[K++] = arr[L++]; //選左邊
        else
            arrtmp[K++] = arr[R++]; //選右邊
    }
    for(int it = left; it < right; it++) //合併
        arr[it] = arrtmp[it];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    mergesort(0, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
