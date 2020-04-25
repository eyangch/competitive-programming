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

vector<int> scores;

int siz[200000];

set<int> been;

int dfsiz(int n, vector<int> graph[200000], int idx, int dist){
    if(been.find(idx) != been.end()){
        return 0;
    }
    been.insert(idx);
    int ret = 1;
    for(int i : graph[idx]){
        ret += dfsiz(n, graph, i, dist + 1);
    } 
    siz[idx] = ret - dist;
    return ret;
}

int main(){
    int n, k; cin >> n >> k;
    vector<int> graph[200000];
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);   
    }
    dfsiz(n, graph, 0, 1);
    sort(siz, siz + n, greater<int>());
    ll ans = 0;
    for(int i = 0; i < n - k; i++){
        ans += siz[i];
    }
    cout << ans << endl;
    return 0;
}


