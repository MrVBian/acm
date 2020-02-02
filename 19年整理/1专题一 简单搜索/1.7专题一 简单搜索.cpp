#include <map>
#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int a[5];
int c;
map<pair<int,int> ,int> mp;
map<pair<int,int> ,int> d;
map<char, string> ans;

void bfs(){
    queue<pair<int,int> > q;
    queue<string> path;
    mp[make_pair(0, 0)] = 1;
    q.push(make_pair(0,0));
    path.push("");
    while(!q.empty()){
        pair<int,int> p;
        p = q.front();
        q.pop();
        string s = path.front();
        path.pop();
        if(p.first == c || p.second == c){
            cout<<d[p]<<endl;
            for(int i = 0; i < s.size(); ++i){
                cout<<ans[s[i]]<<endl;
            }
            return ;
        }
        if(p.first < a[0]){
            if(!mp.count(make_pair(a[0], p.second))){
                q.push(make_pair(a[0], p.second));
                d[make_pair(a[0], p.second)] = d[p] + 1;
                mp[make_pair(a[0], p.second)] = 1;
                path.push(s+"1");
            }
            if(p.second){
                int v1 = p.second + p.first > a[0] ? a[0] : p.second + p.first;
                int v2 = p.second + p.first > a[0] ? p.second + p.first - a[0] : 0;
                if(!mp.count(make_pair(v1, v2))){
                    q.push(make_pair(v1, v2));
                    d[make_pair(v1, v2)] = d[p] + 1;
                    mp[make_pair(v1, v2)] = 1;
                    path.push(s+"2");
                }
            }
        }
        if(p.second < a[1]){
            if(!mp.count(make_pair(p.first, a[1]))){
                q.push(make_pair(p.first, a[1]));
                d[make_pair(p.first, a[1])] = d[p] + 1;
                mp[make_pair(p.first, a[1])] = 1;
                path.push(s+"3");
            }
            if(p.first){
                int v2 = p.second + p.first > a[1] ? a[1] : p.second + p.first;
                int v1 = p.second + p.first > a[1] ? p.second + p.first - a[1] : 0;
                if(!mp.count(make_pair(v1, v2))){
                    q.push(make_pair(v1, v2));
                    d[make_pair(v1, v2)] = d[p] + 1;
                    mp[make_pair(v1, v2)] = 1;
                    path.push(s+"4");
                }
            }
        }
        if(p.first){
            if(!mp.count(make_pair(0, p.second))){
                q.push(make_pair(0, p.second));
                d[make_pair(0, p.second)] = d[p] + 1;
                mp[make_pair(0, p.second)] = 1;
                path.push(s+"5");
            }
        }
        if(p.second){
            if(!mp.count(make_pair(p.first, 0))){
                q.push(make_pair(p.first, 0));
                d[make_pair(p.first, 0)] = d[p] + 1;
                mp[make_pair(p.first, 0)] = 1;
                path.push(s+"6");
            }
        }
    }
    cout<<"impossible"<<endl;
}

int main(){
    ans['1'] = "FILL(1)";
    ans['2'] = "POUR(2,1)";
    ans['3'] = "FILL(2)";
    ans['4'] = "POUR(1,2)";
    ans['5'] = "DROP(1)";
    ans['6'] = "DROP(2)";
    while(cin>>a[0]>>a[1]>>c){
        if(a[0] == c || a[1] == c){
            cout<<1<<endl;
            if(a[0] == c)
                cout<<"FILL(1)"<<endl;
            else
                cout<<"FILL(2)"<<endl;
            continue; 
        }
        if(a[0] < c && a[1] < c){
            cout<<"impossible"<<endl;
            continue;
        }
        d.clear();
        mp.clear();
        bfs();
    }
    return 0;
}
