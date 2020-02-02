#include<bits/stdc++.h>
using namespace std;

void Floyd()
{
    int i,j,k;
    for(i=0;i<verNum;i++)
        for(j=0;j<verNum;j++){
            D[i][j]=G[i][j];//GÔ­Í¼
            path[i][j]=-1;
    }
    for(k=0;k<verNum;k++)
        for(i=0;i<verNum;i++)
            for(j=0;j<verNum;j++)
                if(D[i][k]+D[k][j]<D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    path[i][j]=k;//µÝ¹éÊä³öÂ·¾¶
                }
}

int Find(int a[],int l,int r,int key){
    int m;
    while(l<=r){
        m=(l+r)>>1;
        if(a[m]==key)   return m;
        else if(key>a[m])   l=m+1;
        else    r=m-1;
    }
    return -1;
}

void Path(int i,int j){
    int k=path[i][j];
    if(k<0){
        cout<<i<<"->"<<j<<"  ";
    }
    else{
        Path(i,k);
        Path(k,j);
    }
}

int Find(int x) {return fat[x]==x?x:fat[x]=Find(fat[x]);}

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
