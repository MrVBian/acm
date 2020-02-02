#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool mp[5][6];
int x,y,num;
int step[2][8]={ {1,1,2,2,-1,-1,-2,-2 } ,{ 2,-2,1,-1,2,-2,1,-1 } };

void Sea(int lx,int ly)
{
    int cur_x,cur_y;
    for(int i=0;i<8;i++){
        cur_x=lx+step[0][i];
        cur_y=ly+step[1][i];
        if(cur_x==x&&cur_y==y){
            num++;

        }
        else if(cur_x>=1&&cur_x<=4&&cur_y>=1&&cur_y<=5&& !mp[cur_x][cur_y]){
            mp[cur_x][cur_y]=1;
            Sea(cur_x,cur_y);
            mp[cur_x][cur_y]=0;
        }
    }
}

int main()
{
    cin>>x>>y;
    if(x<1||x>4||y<1||y>5){
        cout<<"ERROR";return 0;
    }
    memset(mp,0,sizeof(mp));
    mp[x][y]=1;
    num=0;
    Sea(x,y);
    cout<<num;
}


//Problem Description
//在一个4*5的棋盘上，马的初始位置坐标（纵 横）位置由键盘输入，求马能返回初始位置的所有不同走法的总数（马走过的位置不能重复，马走“日”字）。如果马的初始位置坐标超过棋盘的边界，则输出ERROR。例如初始位置为4 6，则输出ERROR。
//Input
//输入数据只有一行，有两个用空格分开的整数，表示马所在的初始位置坐标。首行首列位置编号为（1 1）。
//Output
//输出一行，只有一个整数，表示马能返回初始位置的所有不同走法的总数。
//
//如果输入的马的初始位置超出棋盘边界，则输出ERROR。
//Sample Input
//2 2
//Sample Output
//4596
