#include<bits/stdc++.h>
#include<cstring>
using namespace std;

struct node{
    int x,y;
};
int N,M,T;
char mp[8][8];
node Begin,End;
int dir[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
bool Tap=false;

bool OutBorder(int x,int y){
    if(x<0||x>=N||y<0||y>=M)
        return true;
    return false;
}

int OddOrEven(int x,int y){
    return abs(x-End.x)+abs(y-End.y);
}

void dfs(int x,int y,int t){
    if(Tap)
        return ;
    //printf("X: %d  Y:%d t: %d\n",x,y,t);
    int temp=OddOrEven(x,y);
    temp=T-t-temp;
    if( temp<0 ||temp&1 || t>T)
        return ;
    if(t==T&&x==End.x&&y==End.y){
        Tap=true;
        return ;
    }
    for(int i=0;i<4;i++){
        int cur_x=x+dir[i][0];
        int cur_y=y+dir[i][1];
        if(!OutBorder(cur_x,cur_y)&&(mp[cur_x][cur_y]!='X')){
            mp[cur_x][cur_y]='X';
            dfs(cur_x,cur_y,t+1);
            mp[cur_x][cur_y]='.';
            if(Tap)
                return ;
        }
    }
}
//6 6 37
//S.....
//......
//......
//......
//......
//D.....
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>N>>M>>T,N&&M&&T){
        Tap=false;
        int cnt=0;
        for(int i=0;i<N;i++){
            cin>>mp[i];
            for(int j=0;j<M;j++){
                if(mp[i][j]=='D')   End.x=i,End.y=j;
                else if(mp[i][j]=='S')   Begin.x=i,Begin.y=j;
                else if(mp[i][j]=='X')  cnt++;
            }
        }
        if(N*M-cnt<=T)
            Tap=false;
        else{
            mp[Begin.x][Begin.y]='X';
            dfs(Begin.x,Begin.y,0);
        }printf("%s\n",Tap==true?"YES":"NO");
    }
}

//Tempter of the Bone
//Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
//Total Submission(s): 147757    Accepted Submission(s): 39379
//
//
//Problem Description
//The doggie found a bone in an ancient maze, which fascinated him a lot. However, when he picked it up, the maze began to shake, and the doggie could feel the ground sinking. He realized that the bone was a trap, and he tried desperately to get out of this maze.
//
//The maze was a rectangle with sizes N by M. There was a door in the maze. At the beginning, the door was closed and it would open at the T-th second for a short period of time (less than 1 second). Therefore the doggie had to arrive at the door on exactly the T-th second. In every second, he could move one block to one of the upper, lower, left and right neighboring blocks. Once he entered a block, the ground of this block would start to sink and disappear in the next second. He could not stay at one block for more than one second, nor could he move into a visited block. Can the poor doggie survive? Please help him.
//
//
//Input
//The input consists of multiple test cases. The first line of each test case contains three integers N, M, and T (1 < N, M < 7; 0 < T < 50), which denote the sizes of the maze and the time at which the door will open, respectively. The next N lines give the maze layout, with each line containing M characters. A character is one of the following:
//
//'X': a block of wall, which the doggie cannot enter;
//'S': the start point of the doggie;
//'D': the Door; or
//'.': an empty block.
//
//The input is terminated with three 0's. This test case is not to be processed.
//
//
//Output
//For each test case, print in one line "YES" if the doggie can survive, or "NO" otherwise.
//
//
//Sample Input
//4 4 5
//S.X.
//..X.
//..XD
//....
//3 4 5
//S.X.
//..X.
//...D
//0 0 0
//
//
//Sample Output
//NO
//YES


