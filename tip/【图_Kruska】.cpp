#include<iostream>
#include<cstring>
#define vertex 6
#define arcNum 10
using namespace std;
struct node{
    int from;
    int to;
    int weight;
};
int parent[vertex];

node edge[arcNum]={{1,4,12},
                {2,3,17},
                {0,5,19},
                {2,5,25},
                {3,5,25},
                {4,5,26},
                {0,1,34},
                {3,4,38},
                {0,2,46}
                };

int Find(int *parent,int x)
{
    if(parent[x]<0)
        return x;
    else
        return Find(parent,parent[x]);
}

int Kruskal()
{
    memset(parent,-1,sizeof(parent));
    int num=0,sum=0;
    int vex1,vex2;
    for(int i=0;i<vertex;i++){
        vex1=edge[i].from;
        vex2=edge[i].to;
        vex1=Find(parent,vex1);
        vex2=Find(parent,vex2);
        if(vex1!=vex2){
            parent[vex2]=vex1;
            num++;
            sum+=edge[i].weight;
            if(num==vertex-1)
                return sum;
        }
    }
}

int PKruskal()
{
    memset(parent,-1,sizeof(parent));
    int num=0,sum=0;
    int vex1,vex2;
    for(int i=0;i<vertex;i++){
        vex1=edge[i].from;
        vex2=edge[i].to;
        cout<<"±»¿¼²ì±ß£º"<<vex1<<"  "<<vex2<<"  "<<edge[i].weight<<"    ";
        int vex3=vex1,vex4=vex2;
        vex1=Find(parent,vex1);
        vex2=Find(parent,vex2);
        if(vex1!=vex2){
            cout<<"Êä³öTE£º"<<vex1<<"  "<<vex2<<"  "<<edge[i].weight<<endl;
            cout<<"parent:";
            for(int j=0;j<vertex;j++)
                cout<<parent[j]<<"  ";
            cout<<endl;
            parent[vex2]=vex1;
            num++;
            sum+=edge[i].weight;
            if(num==vertex-1)
                return sum;
        }
        else
            cout<<endl;
    }
}

int main()
{
    cout<<PKruskal()<<endl;
    for(int i=0;i<vertex;i++)
        cout<<parent[i]<<"  ";
}

