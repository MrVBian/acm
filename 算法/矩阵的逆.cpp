#include<bits/stdc++.h>
using namespace std;

/*
    O(n³)
    输入:A    原矩阵
         C    逆矩阵
         N    矩阵的阶数
*/

inline vector<double> operator * (vector<double> a, double b) {
    int N = a.size();
    vector<double> res(N, 0);
    for (int i = 0 ; i < N; i++)
        res[i] = a[i] * b;
    return res;
}
inline vector<double> operator - (vector<double> a, vector<double> b){
    int N = a.size();
    vector<double> res(N, 0);
    for (int i = 0; i < N; i++)
        res[i] = a[i] - b[i];
    return res;
}
inline void
