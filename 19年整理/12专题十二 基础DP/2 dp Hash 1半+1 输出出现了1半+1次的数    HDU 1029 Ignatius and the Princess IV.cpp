#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while(~scanf("%d", &n)){
        int ans, v, cot = 0;
        while(n--){
            scanf("%d", &v);
            if(cot)
                v == ans ? ++cot : --cot;
            else{
                ++cot;
                ans = v;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
