/* ***********************************************
MYID    : Chen Fan
LANG    : G++
PROG    : Size Balanced Tree
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1000

typedef struct sbtnod
{
    int key,left,right,size;
} sbtnode;
int sbttail,sbt;

sbtnode tree[MAXN];

void rrotate(int& t)
{
    int k=tree[t].left;
    if (!k) return ;
    tree[t].left=tree[k].right;
    tree[k].right=t;
    tree[k].size=tree[t].size;
    tree[t].size=tree[tree[t].left].size+tree[tree[t].right].size+1;
    t=k;
}

void lrotate(int& t)
{
    int k=tree[t].right;
    if (!k) return ;
    tree[t].right=tree[k].left;
    tree[k].left=t;
    tree[k].size=tree[t].size;
    tree[t].size=tree[tree[t].left].size+tree[tree[t].right].size+1;
    t=k;
}

void maintain(int& t,bool flag)
{
    if (!t) return ;
    if (!flag)
        if (tree[tree[tree[t].left].left].size>tree[tree[t].right].size) rrotate(t);
        else if (tree[tree[tree[t].left].right].size>tree[tree[t].right].size)
        {
            lrotate(tree[t].left);
            rrotate(t);
        } else return ;
    else
        if (tree[tree[tree[t].right].right].size>tree[tree[t].left].size) lrotate(t);
        else if (tree[tree[tree[t].right].left].size>tree[tree[t].left].size)
        {
            rrotate(tree[t].right);
            lrotate(t);
        } else return ;

    maintain(tree[t].left,false);
    maintain(tree[t].right,true);
    maintain(t,false);
    maintain(t,true);
}

void insert(int& t,int v)
{
    if (!t)
    {
        sbttail++;
        tree[sbttail].key=v;
        tree[sbttail].size=1;
        t=sbttail;
    } else
    {
        tree[t].size++;
        if (v<tree[t].key) insert(tree[t].left,v);
        else insert(tree[t].right,v);
        maintain(t,v>=tree[t].key);
    }
}

int del(int& t,int v)
{
    int ret;
    tree[t].size--;
    if (v==tree[t].key||(v<tree[t].key&&tree[t].left==0)||(v>tree[t].key&&tree[t].right==0))
    {
        ret=tree[t].key;
        if (tree[t].left==0||tree[t].right==0) t=tree[t].left+tree[t].right;//
        else tree[t].key=del(tree[t].left,tree[t].key+1);
    } else
    {
        if (v<tree[t].key) ret=del(tree[t].left,v);
        else ret=del(tree[t].right,v);
    }
    return ret;
}

int select(int t,int k)
{
    if (k==tree[tree[t].left].size+1) return t;
    if (k<=tree[tree[t].left].size) return select(tree[t].left,k);
    else return select(tree[t].right,k-1-tree[tree[t].left].size);
}

int search(int t,int x)
{
    if (t==0||x==tree[t].key) return t;
    if (x<tree[t].key) return search(tree[t].left,x);
    else return search(tree[t].right,x);
}

int getmin(int t)
{
    int i=t;
    while(tree[i].left)
    {
        i=tree[i].left;
    }
    return i;
}

int getmax(int t)
{
    int i=t;
    while(tree[i].right)
    {
        i=tree[i].right;
    }
    return i;
}

int pred(int& t,int y,int v)
{
    if (!t) return y;
    if (tree[t].key<v) return pred(tree[t].right,t,v);
    else return pred(tree[t].left,y,v);
}

int succ(int& t,int y,int v)
{
    if (!t) return y;
    if (tree[t].key>=v) return succ(tree[t].left,t,v);
    else return succ(tree[t].right,y,v);
}

void deb_out()
{
    printf("-------\n");
    printf("sbttail=%d sbt=%d\n",sbttail,sbt);
    for    (int i=1;i<=sbttail;i++)
    printf("%2d: key=%2d size=%2d left=%2d right=%2d\n",i,tree[i].key,tree[i].size,tree[i].left,tree[i].right);
    printf("-------\n");
}

int main()
{
    memset(tree,0,sizeof(tree));
    sbttail=0;
    sbt=0;

    for    (int i=1;i<=15;i++) insert(sbt,i);
    deb_out();

    //printf("%d\n",del(sbt,8));
    insert(sbt,8);
    deb_out();
    del(sbt,8);
    del(sbt,8);
    printf("%d\n",search(sbt,8));
    deb_out();
}
