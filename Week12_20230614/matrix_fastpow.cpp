//矩陣快速冪
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mothers_rosario ios_base::sync_with_stdio(0),cin.tie(0);
const int MOD = 1e9+7;

//矩陣乘法
vector<vector<ll> > matrix_mult(vector<vector<ll> > a, vector<vector<ll> > b){ //0base 矩陣乘法,傳入以及輸出二階矩陣
    int ax = a[0].size(), ay = a.size(); //x表行數  
    int bx = b[0].size(), by = b.size(); //y表列數
    //              ax = a[0].size = 3
    //  ay=        [[a11,a12,a13]
    // a.size = 2   [a21,a22,a23]]
    if(ax = by){ //M(ay*ax) * M(by*bx) = M(ay*bx), [if ax == by]
        vector<vector<ll> > ret(ay, vector<ll>(bx, 0)); //建立一個列ay, 行bx, 初始值0的矩陣
        for(int i = 0; i < ay; i++){ //i跑列數
            for(int j = 0; j < bx; j++){ //j跑行數
                for(int k = 0; k < ax; k++){ //k跑內積
                    ret[i][j] = (ret[i][j] + a[i][k] * b[k][j])%MOD; //ret_ij = sum(a_ik*b_kj, k = 0~ax-1)
                }
            }
        }
        return ret;
    }else{
        return vector<vector<ll> > (); //回傳空矩陣
    }
}

//方陣快速冪
vector<vector<ll> > matrix_fastpow(vector<vector<ll> > a, int n){
    int size = a.size();
    vector<vector<ll> > ret(size, vector<ll>(size, 0));
    for(int i = 0; i < a.size(); i++) ret[i][i] = 1; //ret = 單位矩陣
    vector<vector<ll> > fac = a;

    for(; n > 0; n>>=1){
        if(n%2) ret = matrix_mult(ret, fac);
        fac = matrix_mult(fac, fac);
    }

    return ret;
}



int main(){//mothers_rosario
    int size;
    cout << "matrix size:";
    cin >> size;
    vector<vector<ll> > a(size, vector<ll>(size));
    int n;
    cout << "input matrix:\n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin >> a[i][j];
        }
    }
    cout << "n:";
    cin >> n;

    vector<vector<ll> > ret = matrix_fastpow(a,n);
    cout << "A^n :\n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
}