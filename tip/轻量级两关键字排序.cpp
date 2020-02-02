#include<bits/stdc++.h>

using namespace std;

typedef struct Stone{
    int w;
    int p;
}stone;


void Sort(stone s[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(s[j].w>s[j+1].w){
                stone temp;
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
            if(s[j].w==s[j+1].w){
                if(s[j].p<s[j+1].p){
                    stone temp;
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }
    }
}

void QuickSort(stone s[], int n)
{
    int i, j, k;
    stone temp;
    for(i= 0; i < n-1; i++)
    {
        k  =i;
        for(j = i+1; j < n; j++)
        {
            if(s[j].w < s[k].w)
            {
                k  =j;
            }
            else if(s[j].w == s[k].w)
            {
                if(s[j].p > s[k].p)
                {
                    k = j;
                }
            }
        }
        if(k != i)
        {
            temp = s[k];
            s[k] = s[i];
            s[i] = temp;
        }
    }
}

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        stone s[n];
        for(int i=0;i<n;i++){
            scanf("%d %d",&s[i].w,&s[i].p);
        }
        QuickSort(s,n);
//        for(int i=0;i<n;i++){
//            cout<<s[i].w<<' '<<s[i].p<<endl;
//        }
        int sum=0;
        for(int i=0;i<m;i++)
            sum+=s[i].p;
        printf("%d\n",sum);
    }
}


