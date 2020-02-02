#include<iostream>
#include<stack>
#include<climits>
#include<cstring>
using namespace std;

const int inf = 100000000;
const int maxn = 2010;

int n,v,m;
int d[maxn];
int G[maxn][maxn];
int vst[maxn];
int path[maxn];

void Path(int v0, int v1){
    stack<int> s;
    while(v0 != v1){
        s.push(v1);
        v1 = path[v1];
    }
    s.push(v1);
    while(!s.empty()){
        cout<<s.top()<<"  ";
        s.pop();
    }
}

void Dijkstra(int s)
{
    memset(vst,0,sizeof(vst));
    for(int i = 1; i <= m; ++i){
        d[i] = G[1][i];
        vst[i] = 0;
    }

    d[s]=0;
    vst[s] = 1;
    for(int i=1;i<=m;i++){
        int temp=inf;
        int k=s;
        for(int j=1;j<=m;j++){
            if(!vst[j]&&d[j]<temp){
                temp=d[j];
                k=j;
            }
        }
        vst[k]=1;
        for(int j=1;j<=m;j++){
            if(!vst[j]){
                if(d[j]>d[k]+G[k][j])
                    path[j] = k;
                d[j]=min(d[j],d[k]+G[k][j]);
            }
        }
    }
}

int main(){
    while(~scanf("%d %d", &n, &m)){
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= m; ++j){
                G[i][j] = inf;
            }
        }
        for(int i = 0;i < n;i++){
            int x,y,w;
            scanf("%d %d %d", &x, &y, &w);
            if( w < G[x][y] ){
                G[x][y] = w;
                G[y][x] = w;
            }
        }
        Dijkstra(1);

        /*
        cout << endl;
        for(int i = 1; i <= 5; ++i){
            cout<<"//////////  "<<i<<"///////"<<endl;
            Path(1, i);
            cout<<endl<<"now _ d :  "<<d[i]<<endl;
            cout<<endl<<endl;
        }
        cout<<endl<<endl;
        cout << "***********" << endl;
        */
        printf("%d\n", d[m]);
    }
    return 0;
}