#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[100];
int m[7][7];
int main()
{
    int A,B,n;
    while(scanf("%d%d%d",&A,&B,&n),A&&B&&n){
        memset(m,0,sizeof(m));
        int x,y;
        f[1]=f[2]=x=y=1;
        int k=3;
        while(!m[x][y]){
            m[x][y]=k;
            f[k]=( A*y + B*x )%7;
            x=f[k-1];
            y=f[k];
            k++;
        }
        int a=m[x][y],b=k-a;
        if(n<k)
            printf("%d\n",f[n]);
        else
            printf("%d\n",f [(n-a)%b+a] );
    }
}
