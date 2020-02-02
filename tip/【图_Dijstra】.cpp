#include<iostream>
#include<stack>
#include<climits>
#include<cstring>
using namespace std;
int n,v,m;
int d[1000];
int G[1000][1000];
int path[1000];
int vst[1000];

void Path(int v,int v0){
    stack<int> s;
    while(v!=v0){
        s.push(v);
        v=path[v];
    }
    s.push(v);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void Dijkstra(int s)
{
    fill(d,d+n,INT_MAX);
    fill(path,path+n,-1);
    memset(vst,0,sizeof(vst));
    d[s]=0;
    for(int i=0;i<n-1;i++){
        int temp=INT_MAX;
        int k=-1;
        for(int j=0;j<n;j++){
            if(!vst[j]&&d[j]<temp){
                temp=d[j];
                k=j;
            }
        }
        if(k==-1)
            break;
        vst[k]=1;
        for(int j=0;j<n;j++){
            if(G[k][j]){
                if(d[j]>d[k]+G[k][j])
                    path[j]=k;
                d[j]=min(d[j],d[k]+G[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i!=s)
            Path(i,s);
        cout<<d[i]<<endl;
    }
}

int main(){
	while(cin >> n >> m){
		for(int i = 0;i < m;i++){
			int x,y,w;
			cin >> x >> y >> w;
			G[x][y] = w;
			G[y][x] = w;
		}
		int s;
		cin >> s;
		Dijkstra(s);
	}
	return 0;
}
//5 7
//0 1 100
//0 2 30
//0 4 10
//2 1 60
//2 3 60
//3 1 10
//4 3 50


//0 4 3 1 70
//0 2 30
//0 4 3 60
//0 4 10
