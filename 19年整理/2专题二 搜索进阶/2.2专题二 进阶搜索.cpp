#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e8;
const int MAXN = 4e5;
int n,m;
char eight_num[9][10] = {"X12345678","1X2345678","12X345678","123X45678","1234X5678","12345X678",
                         "123456X78","1234567X8","12345678X"};
char step[] = "dlru";
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
int fac[9] = {1,1,2,6,24,120,720,5040,40320};
int vis[9][MAXN];
int pre[9][MAXN];
struct node{
    int num[9];//八数码
    int state;//状态（康托展开值）
    int pos;//x的位置
};
//得到状态
int Cantor(int *s){
    int sum = 0;
    for(int i = 0; i < 9; i++){
        int num = 0;
        for(int j = i+1; j < 9; j++){
            if(s[i] > s[j]) num++;
        }
        sum += num * fac[8-i];
    }
    return sum;
}
void printAns(int state,int kind){
    string ans;
    while(state != -1){
        ans += step[vis[kind][state]];
        state = pre[kind][state];
    }
    printf("%d\n",ans.size()-1);
    for(int i = ans.size() - 2; i >= 0; i--){
        printf("%c",ans[i]);
    }
    puts("");
}
void bfs(node x,int kind){
    queue<node> q;
    q.push(x);
    vis[kind][x.state] = 1;//这个是初始化的值并不是真正走的值所以上面输出的时候是从倒数第二个开始输出
    while(!q.empty()){
        node u = q.front();
        q.pop();
        //4种交换
        int x = u.pos / 3;
        int y = u.pos % 3;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx < 3 && yy >= 0 && yy < 3){
                node v = u;
                swap(v.num[u.pos],v.num[xx*3+yy]);
                v.state = Cantor(v.num);
                if(vis[kind][v.state] == -1){
                    v.pos = xx * 3 + yy;
                    vis[kind][v.state] = i;//代表通过i方向的移动到达kind这类中的v.state状态
                    pre[kind][v.state] = u.state;//记录这种状态的前一种状态
                    q.push(v);
                }
            }
        }
    }
}
void init(char *s,int kind){
    node u;
    for(int i = 0; i < 9; i++){
        if(s[i] == 'X'){
            u.num[i] = 0;
            u.pos = i;
        }
        else u.num[i] = s[i] - '0';
    }
    u.state = Cantor(u.num);
    bfs(u,kind);
}
int main(){
    int t,cas = 0;
    char s[15],c[15];
    int kind;
    int temp[MAXN];
    memset(vis,-1,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    for(int i = 0; i < 9; i++){
        init(eight_num[i],i);
    }
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int cnt = 1;
        //映射初始状态的八数码
        for(int i = 0; i < 9; i++){
            if(s[i] == 'X'){
                c[0] = 0;
                kind = i;
            }
            else c[s[i]-'0'] = cnt++;
        }
        //映射目标状态八数码
        scanf("%s",s);
        for(int i = 0; i < 9; i++){
            if(s[i] == 'X') temp[i] = c[0];
            else temp[i] = c[s[i]-'0'];
        }
        int state = Cantor(temp);
        printf("Case %d: ",++cas);
        printAns(state,kind);
    }
    return 0;
}