#include <iostream>
#include <set>

using namespace std;
string a, b, c;
set<string> s;
int n, t, m;

void dfs(){
    string mo;
    int cot = 0;
    while(1){
        mo = "";
        for(int i = 0; i < n; ++i){
            mo = mo + b[i] + a[i];
        }
        if(s.find(mo) == s.end())
            s.insert(mo);
        else
            break;
        cot ++;
        if(mo.compare(c) == 0){
            cout << m << " " << cot << endl;
            return ;
        }
        a = mo.substr(0,n);
        b = mo.substr(n,2*n);
    }
    cout << m << " " << -1 << endl;
}

int main(){
    cin >> t;
    for(m = 1; m <= t; ++m){
        s.clear();
        cin >> n;
        cin >> a >> b >> c;
        dfs();
    }
}