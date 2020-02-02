#include<iostream>
#include<iomanip>
using namespace std;
#define INF 5000
#define verNum 6
#define arcNum 6

int G[verNum][verNum]={ {INF,7,4,INF,INF,INF},  //≤‚ ‘MGraph
                            {7,INF,6,2,INF,4},
                            {4,6,INF,INF,9,8},
                            {INF,2,INF,INF,INF,7},
                            {INF,INF,9,INF,INF,1},
                            {INF,4,8,7,1,INF},
                          };

int D[verNum][verNum];
int path[verNum][verNum];

void Floyd()
{
    int i,j,k;
    for(i=0;i<verNum;i++)
        for(j=0;j<verNum;j++){
            D[i][j]=G[i][j];//G‘≠Õº
            path[i][j]=-1;
    }
    for(k=0;k<verNum;k++)
        for(i=0;i<verNum;i++)
            for(j=0;j<verNum;j++)
                if(D[i][k]+D[k][j]<D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    path[i][j]=k;//µ›πÈ ‰≥ˆ¬∑æ∂
                }
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

int main()
{
    Floyd();
    cout<<"Floyd:"<<endl;
    for(int i=0;i<verNum;i++){
        for(int j=0;j<verNum;j++)
            cout<<setw(3)<<D[i][j];
        cout<<endl;
    }
    cout<<endl<<endl;

    cout<<"Path:"<<endl;
    for(int i=0;i<verNum;i++){
        for(int j=0;j<verNum;j++)
            cout<<setw(3)<<path[i][j];
        cout<<endl;
    }
    cout<<endl<<endl;

    cout<<"(0,5):";
    Path(0,5);
    cout<<endl;
    cout<<"(2,3):";
    Path(2,3);
    cout<<endl;
    cout<<"(1,4):";
    Path(1,4);
    cout<<endl;
    cout<<"(3,4):";
    Path(3,4);
    cout<<endl;
    return 0;
}

