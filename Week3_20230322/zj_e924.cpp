#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,temp,tmp2; //temp用來存括號代碼的
    cin >> n;
    cin.ignore(); //避免getline吃到\n

    for(int i = 0;i<n;i++){
        int ok=1;
        string input;
        getline(cin , input);
        stack<int> list;
        for(int i = 0;i<input.size();i++){//處理input的index
            switch (input[i]) //(){}[]<> = 12345678
            {
            case '(':
                temp = 1;
                break;
            case ')':
                temp = 2;
                break;
            case '{':
                temp = 3;
                break;
            case '}':
                temp = 4;
                break;
            case '[':
                temp = 5;
                break;
            case ']':
                temp = 6;
                break;
            case '<':
                temp = 7;
                break;
            case '>':
                temp = 8;
                break;
            }
            
            if(temp%2){ //新增
                list.push(temp);
            }else{ //消掉
                if(list.empty()){
                    ok = 0;
                }else if(list.top()+1 == temp){
                    list.pop();
                }else{
                    ok = 0;
                }
            }

            //cout<<temp;
            //if(ok == 0) {cout<<"N\n";}
            //else{cout<<"Y\n";}
            
        }

        if(ok==0 || !list.empty()){
            cout << "N\n" ;
        }else{
            cout << "Y\n" ;
        }

    }
    
}