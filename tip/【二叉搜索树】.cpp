#include<iostream>
#include<queue>
#include<cstddef>
using namespace std;

typedef struct BinNode *BinTree;
struct BinNode{
    int Data;
    BinTree Left;
    BinTree Right;
};


//二叉搜索树的插入算法
BinTree Insert(BinTree T,int x)
{
    if(!T){
        T=new BinNode;
        T->Data=x;
        T->Right=T->Left=NULL;
    }else{
        if(T->Data>x)
            T->Left=Insert(T->Left,x);
        else if(T->Data<x)
            T->Right=Insert(T->Right,x);
        else
            ;//已存在该值
    }
    return T;
}

BinTree CreateTree(BinTree T,int n)
{
    int x;
    cin>>x;
    n--;
    T=new BinNode;
    T->Data=x;
    T->Left=T->Right=NULL;
    while(n--){
        cin>>x;
        Insert(T,x);
    }
    return T;
}

void LeverOrderTraversal(BinTree T)
{
    BinTree p;
    p=T;
    queue<BinTree> q;
    q.push(p);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->Data<<"  ";
        if(p->Left)
            q.push(p->Left);
        if(p->Right)
            q.push(p->Right);
    }
}

//递归搜索树
BinTree Find(BinTree T,int x)
{
    if(!T)
        return NULL;
    if(T->Data>x)
        return Find(T->Left,x);
    else if(T->Data<x)
        return Find(T->Right,x);
    else
        return T;
}


//迭代搜索树
BinTree DFind(BinTree T,int x)
{
    while(T){
        if(T->Data>x)
            T=T->Left;
        else if(T->Data<x)
            T=T->Right;
        else
            return T;
    }
    return NULL;
}


//递归搜索最小最大值
BinTree FindMax(BinTree T)
{
    if(!T)
        return NULL;
    if(!T->Right)
        return T;
    else
        return FindMax(T->Right);
}

BinTree FindMin(BinTree T)
{
    if(!T)
        return NULL;
    if(!T->Left)
        return T;
    else
        return FindMin(T->Left);
}


//迭代搜索最大最小值
BinTree DFindMax(BinTree T)
{
    if(T)
        while(T->Right)
            T=T->Right;
    return T;
}

BinTree DFindMin(BinTree T)
{
    if(T)
        while(T->Left)
            T=T->Left;
    return T;
}


BinTree Delete(BinTree T,int x)
{
    if(!T)
        cout<<"删除的值不存在"<<endl;
    else if(T->Data>x)
        T->Left=Delete(T->Left,x);//可以调用先前写好的Find 在Find返回为NULL时输出"删除的值不存在"
    else if(T->Data<x)
        T->Right=Delete(T->Right,x);
    else{
        BinTree temp;
        if(T->Right&&T->Left){
            temp=DFindMax(T->Left); //左子树最大值或右子树最小值
          //temp=DFindMin(T->Right);
            T->Data=temp->Data;
            T->Left=Delete(T->Left,T->Data);
          //T->Right=Delete(T->Right,T->Data);
        }
        else{
            temp=T;
            if(!T->Left)
                T=T->Right;
            else if(!T->Right)
                T=T->Left;
            delete temp;
        }
    }
    return T;
}

void InOrderTraversal(BinTree BT)
{
	if(BT){
		InOrderTraversal(BT->Left);
		cout<<BT->Data<<"  ";
		InOrderTraversal(BT->Right);
	}
}

int main()
{
    BinTree T;
    cout<<"请输入所建搜索Binary Tree的数据数量：";
    int n;
    cin>>n;
    cout<<"请输入数据：";
    T=CreateTree(T,n);
    cout<<"层序遍历：";
    LeverOrderTraversal(T);

    cout<<endl;
    cout<<"中序遍历";
    InOrderTraversal(T);


    cout<<endl;
    cout<<"最大值递归："<<FindMax(T)->Data<<"   非递归："<<DFindMax(T)->Data<<endl;
    cout<<"最小值递归："<<FindMin(T)->Data<<"   非递归："<<DFindMin(T)->Data<<endl;

    cout<<"请输入要删除的值：";
    cin>>n;
    Delete(T,n);
    cout<<"层序遍历：";
    LeverOrderTraversal(T);
}
