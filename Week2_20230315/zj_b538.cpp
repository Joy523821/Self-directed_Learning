#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
    if(b>a) return GCD(b,a);
    if(a%b == 0) return b;
    return GCD(b, a%b);
}

struct math{
    int a,b,c,d,gcd,m,n;
    char operate;
};


int main(){
    math x;
    int lcm; //最小公倍數
    while(cin >> x.a >> x.b >> x.c >> x.d >> x.operate){
        if(x.b<0){
            x.b*=-1;
            x.a*=-1;
        }
        if(x.d<0){
            x.c*=-1;
            x.d*=-1;
        }

        x.gcd = GCD(x.b,x.d);
        lcm = x.b*x.d/x.gcd;
        //////////////cout <<"lcm="<<lcm<<" gcd="<<x.gcd<<"\n";////
        x.a *= lcm/x.b; //通分
        x.c *= lcm/x.d;
        //////cout <<"a,c=" << x.a <<" " <<x.c<<"\n";////
        if(x.operate=='+'){
            x.m = x.a+x.c;
            x.n = lcm;
        }else if(x.operate=='-'){
            x.m = x.a-x.c;
            x.n = lcm;
        }else if(x.operate=='*'){
            x.m = x.a*x.c;
            x.n = lcm*lcm;
        }else if(x.operate=='/'){
            x.m = x.a;
            x.n = x.c;
        }

        //cout <<"m,n=" <<x.m<<" "<<x.n<<"\n";//

        if(x.n<0){
            x.m*=-1;
            x.n*=-1;
        }

        if(x.m%x.n==0){
            cout << x.m/x.n << "\n";
        }else{
            cout << x.m/GCD(abs(x.m),x.n) << "/" << x.n/GCD(abs(x.m),x.n) << "\n";
        }
    }
}

