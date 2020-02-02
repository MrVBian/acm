#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
const int maxn=370000;
int fac[10];
int vis[370000];
string ans[maxn];
int Hash[10];
int step[4][3] = {{0,1,1},{0,-1,-1},{1,0,3},{-1,0,-3}};
const int dx[]= {0,0,1,-1};
const int dy[]= {1,-1,0,0};
const int dd[]= {1,-1,3,-3};
char go[]="lrud";
queue<int> q;
void init(){
    fac[0]=1;
    for(int i=1; i<10; i++)
        fac[i]=fac[i-1]*i;
}
int hashh(int k){
    int t,ans=0;
    for(int i=0; i<9; i++){
        Hash[8-i]=k%10;
        k/=10;
    }
    for(int i=0; i<9; i++){
        t=0;
        for(int j=i+1; j<9; j++)
            if(Hash[i]>Hash[j])t++;
        ans+=t*fac[8-i];
    }
    return ans;
}

bool check(int x,int y){
    if(x<0 || x>=3 || y<0 || y>=3)
        return false;
    return true;
}

void bfs(int k){
    while(!q.empty())
        q.pop();
    int hp = hashh(k);
    vis[hp] = 1;
    q.push(k);
    string s;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        hp = hashh(p);
        s = "";
        for(int i = 0; i < 9; ++i){
            s += p%10+48;
            p /= 10;
        }
        reverse(s.begin(), s.end());
        int pos;
        for(int i = 0; i < 9; ++i)
            if(s[i] == '9'){
                pos = i;
                break;
            }
        int x = pos / 3;
        int y = pos % 3;
        for(int i = 0; i < 4; ++i){
            int cur_x = x + step[i][0];
            int cur_y = y + step[i][1];
            if(check(cur_x, cur_y)){
                int cur_p = 0;
                swap(s[pos],s[pos+step[i][2]]);
                for(int j = 0; j < 9; ++j){
                    cur_p *= 10;
                    cur_p += s[j]-48;
                }
                int cur_hp = hashh(cur_p);
                if(!vis[cur_hp]){
                    vis[cur_hp]=1;
                    q.push(cur_p);
                    ans[cur_hp] = ans[hp] + go[i];
                }
                swap(s[pos],s[pos+step[i][2]]);
            }
        }
    }
}
int main(){
    init();
    bfs(123456789);
    for(int i=0; i<maxn; i++)
        reverse(ans[i].begin(),ans[i].end());
    char ch[9];
    while(~scanf("%s", ch)){
        for(int i=1; i<9; i++)scanf("%s",ch+i);
        int k=0;
        for(int i=0; i<9; i++){
            if(ch[i]=='x'){
                ch[i]='9';
                break;
            }
        }
        for(int i=0; i<9; i++){
            k *= 10;
            k += ch[i]-48;
        }
        int hk = hashh(k);
        if(vis[hk])
            cout<<ans[hk]<<endl;
        else
            cout<<"unsolvable"<<endl;
    }
    return 0;
}