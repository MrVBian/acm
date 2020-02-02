#include<stdio.h>
#include<string.h>
int f[31][31][31];

int Calc(int a,int b,int c)
{
    if(a<=0 ||b<=0||c<=0)
        return 1;
    else if(f[a][b][c]>0)
        return f[a][b][c];
    else if(a>20||b>20||c>20)
        return Calc(20,20,20);
    else if(a<b&&b<c)
        return f[a][b][c]=Calc(a,b,c-1)+Calc(a,b-1,c-1)-Calc(a,b-1,c);
    else
        return f[a][b][c]=Calc(a-1,b,c)+Calc(a-1,b-1,c)+Calc(a-1,b,c-1)-Calc(a-1,b-1,c-1);

}

int main()
{
    memset(f,-1,sizeof(f));
    int a,b,c;
    while(~scanf("%d %d %d",&a,&b,&c)){
        printf("%d\n",Calc(a,b,c));
    }
}


/***************************************************
User name: 17¼¶Èí¿ª  ±åÕñÎ°
Result: Accepted
Take time: 20ms
Take Memory: 280KB
Submit time: 2018-05-18 22:34:00
****************************************************/
