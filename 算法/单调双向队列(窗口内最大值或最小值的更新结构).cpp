#include<bits/stdc++.h>

using namespace std;

int *getMaxWindow(int arr[], int arrLen, int w){
    if (arrLen == 0 || w < 1 || arrLen < w) {
        return 0;
    }
    list<int> qmax;
    int *res = new int[arrLen - w + 1];
    int index = 0;
    for (int i = 0; i < arrLen; i++){
        while (!qmax.empty() && arr[qmax.back()] <= arr[i]){//从大到小排列 更新逻辑
            qmax.pop_back();
        }
        qmax.push_back(i);
        if (qmax.front() == i - w){//据窗口而变
            qmax.pop_front();
        }
        if (i >= w - 1){
            res[index++] = arr[qmax.front()];
        }
    }
    return res;
}

int main(){
    int n, w;
    cin>>n>>w;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int *res = getMaxWindow(a, n, w);
    for (int i = 0; i < n - w + 1; i++)
        cout<<res[i]<<"  ";
}
//8
//3
//4 3 5 4 3 3 6 7
