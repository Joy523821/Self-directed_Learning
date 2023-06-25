#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0 ; i < n ; i++ ){
        cin >> vec[i];
    }

    prev_permutation(vec.begin(), vec.end()); //只是排序的函數不能直接拿來當資料結構用!!!!!

    for (int i = 0 ; i < n ; i++ ){
        cout << vec[i] << " ";
    }
}