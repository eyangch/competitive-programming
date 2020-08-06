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

int find(int u, int (&par)[200000]){
    if(par[u] == u){
        return u;
    }
    par[u] = find(par[u], par);
    return par[u];
}

void un(int u, int v, int (&par)[200000], int (&sz)[200000]){
    u = find(u, par);
    v = find(v, par);
    if(u == v){
        return;
    }
    if(sz[u] < sz[v]){
        par[u] = v;
        sz[v] += sz[u];
    }else{
        par[v] = u;
        sz[u] += sz[v];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int N, M; cin >> N >> M;
    vi graph[N];
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);   
    }
    int open[N];
    for(int i = N-1; i >= 0; i--){
        cin >> open[i];
        open[i]--;
    }
    bool opened[N];
    fill(opened, opened+N, false);
    int par[200000], sz[200000];
    for(int i = 0; i < N; i++){
        par[i] = i;
        sz[i] = 1;
    }
    bool ans[N];
    fill(ans, ans+N, false);
    for(int i = 0; i < N; i++){
        opened[open[i]] = true;
        for(int j : graph[open[i]]){
            if(opened[j]){
                un(open[i], j, par, sz);   
            }
        }
        if(sz[find(open[i], par)] == i+1){
            ans[i] = true;
        }
    }
    for(int i = N-1; i >= 0; i--){
        if(ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}


