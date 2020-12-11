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

int N, M;
int par[100000], sz[100000];
int cpn, mxsz = 1;

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
    cpn--;
    par[u] = v;
    sz[v] += sz[u];
    mxsz = max(mxsz, sz[v]);
}

signed main(){
    setIO("");
    cin >> N >> M;
    cpn = N;
    fill(sz, sz+N, 1);
    iota(par, par+N, 0);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        un(a-1, b-1);
        cout << cpn << " " << mxsz << endl;
    }
    return 0;
}


