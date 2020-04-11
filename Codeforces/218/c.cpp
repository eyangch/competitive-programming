#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int main(){
    int n; cin >> n;
    pii c[n];
    for(int i = 0; i < n; i++){
        cin >> c[i].first >> c[i].second;    
    }
    vi graph[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || (c[i].first != c[j].first && c[i].second != c[j].second)) continue;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }
    int ans = -1;
    set<int> been;
    for(int i = 0; i < n; i++){
        if(been.find(i) != been.end()){
            continue;
        }
        ans++;
        queue<int> bfs;
        bfs.push(i);
        been.insert(i);
        while(!bfs.empty()){
            int idx = bfs.front();
            bfs.pop();
            for(int j : graph[idx]){
                if(been.find(j) != been.end()){
                    continue;
                }
                bfs.push(j);
                been.insert(j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}


