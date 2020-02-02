#include<iostream>
#include<climits>
#include<cstdio>
#include<queue>
using namespace std;

typedef struct HeapStruct{
    int *Data;
    int Size;
    int Capacity;
}*MaxHeap;

MaxHeap Create(int MaxSize)
{
    MaxHeap H=new HeapStruct;
    H->Data=new int [MaxSize+1];
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=INT_MAX;
    return H;
}

bool IsFull(MaxHeap H)
{
    return H->Size==H->Capacity;
}

bool IsEmpty(MaxHeap H)
{
    return H->Size==0;
}

void Insert(MaxHeap H,int item)
{
    int i;
    if(IsFull(H)){
        printf("最大堆已满");
        return;
    }
    i=++H->Size;
    for(;H->Data[i/2]<item;i/=2)
        H->Data[i]=H->Data[i/2];
    H->Data[i]=item;
}

int DeleteMax(MaxHeap H)
{
    int Parent,Child;
    int MaxItem,temp;
    if(IsEmpty(H)){
        printf("最大堆已为空");
        return -1;
    }
    MaxItem=H->Data[1];//取出根结点最大值
    //用最大堆中最后一个元素从根结点开始向上过滤下层结点
    temp=H->Data[H->Size--];
    for(Parent=1;Parent*2<=H->Size;Parent=Child){
        Child = Parent * 2;
        if( (Child!=H->Size) &&
            (H->Data[Child] < H->Data[Child+1]) )
            Child++;//Child指向左右子结点的较大者
        if(temp>=H->Data[Child])    break;
        else//移动temp元素到下一层
            H->Data[Parent]=H->Data[Child];
    }
    H->Data[Parent]=temp;
    return MaxItem;
}

void LeverOrderTraversal(MaxHeap H)
{
    for(int i=1;i<=H->Size;i++)
        cout<<H->Data[i]<<"  ";
}

int main()
{
    cout<<"建最大堆"<<endl;
    MaxHeap H;
    H=Create(10);
    int n,m;
    cout<<"请输入堆中元素个数：";
    cin>>n;
    cout<<"请输入堆中元素值：";
    for(int i=0;i<n;i++){
        cin>>m;
        Insert(H,m);
    }
    cout<<"层序遍历：";
    LeverOrderTraversal(H);
    cout<<endl;
    cout<<"删除的堆顶"<<endl;
    DeleteMax(H);
    cout<<"层序遍历：";
    LeverOrderTraversal(H);
}
