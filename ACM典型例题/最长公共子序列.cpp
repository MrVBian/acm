#include<iostream>
#include<string>
#include<memory.h>
#include <stdlib.h>
using namespace std;

//int LCS(string x, string y);
int LCS2(string s1, string s2);


int LCS2(string s1,string s2)
{
    int len1=s1.length();
    int len2=s2.length();

    int leftabove,left,above;
    int *dp=new int [len2+1];
    memset(dp,0,(len2+1)*sizeof(int));
    for(int i=1;i<=len1;i++){
        leftabove=left=dp[0];
        above=dp[1];
        for(int j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1])   dp[j]=leftabove+1;
            else    dp[j]=max(left,above);
            leftabove=above;
            above=dp[j+1];
            left=dp[j];
        }
    }
    cout<<dp[len2]<<endl;
}


int main() {
    string s1, s2;
    while(cin>>s1>>s2){
        LCS2(s1,s2);
    }
}
