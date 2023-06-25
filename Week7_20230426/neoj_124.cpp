//這題是互動題
//solve(n,x,y) : 大小為n*n(1_base)的地 (x,y)為王老先生自己的地
//Report(x1,y1, x2,y2, x3,y3) : 割出來的其中一塊L型包含這三點
#include<bits/stdc++.h>
using namespace std;
/*
    主想法
    因為是二次方邊長，每次切半大小都必定相同
    每次用一個十字把圖切成四等分
    二維遍歷找到第一個已分配的點在哪一塊
    把L行蓋在十字中心相鄰四塊中，沒有第一已分配點的那三塊
    為什麼可以:
    1.從頭到尾跑的十字中心全部不會重複，所以蓋L型的時候絕對不會壓到重覆的
    0000  0000  0000  0001
    0XX0  10X0  0XX0  0X00
    00X0  0XX0  0X00  0XX0
    0100  0000  0001  0000
*/
bool maze[1025][1025]; //用來存哪些點已經分過了

void DQ(int, int, int); //處理指定區塊
void solve(int, int, int);

void solve(int N, int X, int Y){ //長度N 老先生的地在(X,Y)
    memset(maze, 0, sizeof(maze)); //把maze的sizeof(maze)項替換成0
    maze[X][Y] = 1; //占走了
    DQ(1, 1, N);
}

void DQ(int x, int y, int n){ //搜(x,y)開始,長度n*n的區域
    if(n<=1) return; //邊界
    int half = n >> 1, x_pos = 0, y_pos = 0; //half是一半長度
    for(int i = x; i < x+n; i++){ //找並存第一個被占走的
        for(int j = y; j < y+n; j++){
            if(maze[i][j] == 1){
                x_pos = i;
                y_pos = j;
                break;
            }
        }
    }
    int pos; //pos [ 1 3 ]
             //    [ 2 4 ]
    if(x_pos >= x+half){
        if(y_pos >= y+half) pos = 4;
        else pos = 3;
    }else{
        if(y_pos >= y+half) pos = 2;
        else pos = 1;
    }
    int nx = x+half, ny = y+half; //存十字右下的點
    switch (pos) {
        case 1:
            Report(nx,ny, nx-1,ny, nx,ny-1); // 0X
            maze[nx][ny] = 1;                // XI
            maze[nx-1][ny] = 1;  
            maze[nx][ny-1] = 1;
            break;
        case 3:
            nx--;
            Report(nx,ny ,nx+1,ny, nx,ny-1);
            maze[nx][ny] = 1;   // X0
            maze[nx+1][ny] = 1; // IX
            maze[nx][ny-1] = 1;
            break;
        case 2:
            ny--;
            Report(nx,ny ,nx,ny+1, nx-1,ny);
            maze[nx][ny] = 1;   // XI
            maze[nx][ny+1] = 1; // 0X
            maze[nx-1][ny] = 1;
            break;
        case 4:
            nx--; ny--;
            Report(nx,ny ,nx+1,ny, nx,ny+1);
            maze[nx][ny] = 1;   // IX
            maze[nx+1][ny] = 1; // X0
            maze[nx][ny+1] = 1;
            break;
        default:
            break;
    } 
    DQ(x, y, half);
    DQ(x, y+half, half);
    DQ(x+half, y, half);
    DQ(x+half, y+half, half);
}
