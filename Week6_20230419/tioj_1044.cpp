#include <iostream>
#include "lib1044.h" //<-互動題所以
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

//00000111111
//     ^
int main() {_
    int n = Initialize();
    int l = 1; int r = n;
    int mid = (l+r)/2;
    while (r != l) { //左閉右閉
        mid = (l+r)/2;
        if (Guess(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    Report(r);
    return 0;
}