#include<bits/stdc++.h>
using namespace std;

int squArr[505][505];
int presum[505][505]; //2-dimensional
int n,m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> m){
        for(int i = 0; i <= n; i++){//border
            presum[0][i] = 0;
            presum[i][0] = 0;
        }
        for(int i = 1; i <= n; i++){//1base
            for(int j = 1; j <= n; j++){
                cin >> squArr[i][j];
                presum[i][j] = squArr[i][j] + presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1];
            }
        }
        int x1,x2,y1,y2; 
        while(m--){
            cin >> x1 >> y1 >> x2 >> y2;
            cout << presum[x2][y2] - presum[x2][y1 -1] - presum[x1 - 1][y2] + presum[x1 - 1][y1 - 1] << '\n';
        }
    }
}