//矩陣乘法
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
                    ret[i][j] += a[i][k] * b[k][j]; //ret_ij = sum(a_ik*b_kj, k = 0~ax-1)
                }
            }
        }
        return ret;
    }else{
        return vector<vector<ll> > (); //回傳空矩陣
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ay,ax,by,bx; //a,b,c,d
    while(cin >> ay >> ax >> by >> bx){
        if(ax != by){ //不吃輸入
            cout << "Error\n";
        }else{
            vector<vector<ll> > a(ay, vector<ll>(ax));
            vector<vector<ll> > b(by, vector<ll>(bx));
            for(int i = 0; i < ay; i++){
                for(int j = 0; j < ax; j++){
                    cin >> a[i][j];
                }
            }
            for(int i = 0; i < by; i++){
                for(int j = 0; j < bx; j++){
                    cin >> b[i][j];
                }
            }

            vector<vector<ll> > a_mul_b = matrix_mult(a,b);
            for(int i = 0; i < ay; i++){
                for(int j = 0; j < bx; j++){
                    cout << a_mul_b[i][j] << ' ';
                }
                cout << '\n';
            }
            
        }
    }
}