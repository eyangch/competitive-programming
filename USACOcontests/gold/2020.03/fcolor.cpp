#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

void setIO(string s){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(s != ""){
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}

struct setcmp{
    bool operator()(set<int> a, set<int> b){
        return *a.begin() < *b.begin();
    }
};

int N, M;
vi graph[200000];
int par[200000], sz[200000];
int rep[200000];
set<int> components[200000];
set<set<int>, setcmp> sortc;
int ans[200000];

int find(int u){
    if(par[u] == u){
        return u;
    }
    par[u] = find(par[u]);
    return par[u];
}

void un(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return;
    }
    if(sz[u] > sz[v]){
        swap(u, v);
    }
    par[u] = v;
    sz[v] += sz[u];
    int ru = rep[u];
    int rv = rep[v];
    rep[v] = max(rep[v], rep[u]);
    if(ru > -1 && rv > -1){
        un(ru, rv);
    }
}

signed main(){
    setIO("fcolor");
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
    }
    fill(sz, sz+N, 1);
    iota(par, par+N, 0);
    fill(rep, rep+N, -1);
    for(int i = 0; i < N; i++){
        if((int)graph[i].size() > 0){
            rep[i] = graph[i][0];
        }
    }
    for(int i = 0; i < N; i++){
        if((int)graph[i].size() > 0){
            for(int j = 1; j < (int)graph[i].size(); j++){
                un(graph[i][0], graph[i][j]);
            }
        }
    }
    for(int i = 0; i < N; i++){
        components[find(i)].insert(i);
    }
    for(int i = 0; i < N; i++){
        if((int)components[i].size() > 0){
            sortc.insert(components[i]);
        }
    }
    int color = 1;
    for(set<int> i : sortc){
        for(int j : i){
            ans[j] = color;
        }
        color++;
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
