#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;

const int maxn = 100010;

int main() {
    int x, y;
    int t = 1;
    while(~scanf("%d%d", &x, &y)) {
        if(x < 0 && y < 0)
            break;
        if(!x && !y){
            printf("Case %d is a tree.\n", t++);
            continue;
        }
        int cot = 1;
        set<int> s;
        s.clear();
        s.insert(x);
        s.insert(y);
        while(~scanf("%d%d", &x, &y)) {
            if(!x && !y)
                break;
            s.insert(x);
            s.insert(y);
            cot++;
        }

        if(s.size() - cot == 1)
            printf("Case %d is a tree.\n", t++);
        else
            printf("Case %d is not a tree.\n", t++);
    }
    return 0;
}
