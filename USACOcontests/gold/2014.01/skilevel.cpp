#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"
#define int ll

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

struct edge{int u; int v; int d;};
bool cmpe(edge a, edge b){
    return a.d < b.d;
}

int M, N, T;
int b[500][500];

vector<edge> g;

int par[250000], sz[250000], hstart[250000];

int ans = 0;

int cvt(int x, int y){
    return N * x + y;
}

int find(int u){
    if(par[u] == u){
        return u;
    }
    par[u] = find(par[u]);
    return par[u];
}

void un(int u, int v, int d){
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
    hstart[v] += hstart[u];
    if(sz[v] >= T && hstart[v]){
        ans += d * hstart[v];
        hstart[v] = 0;
    }
}

signed main(){
    setIO("skilevel");
    cin >> M >> N >> T;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> hstart[cvt(i, j)];
        }
    }
    edge nxt;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(i > 0){
                nxt = {cvt(i, j), cvt(i-1, j), abs(b[i][j] - b[i-1][j])};
                g.push_back(nxt);
            }if(j > 0){
                nxt = {cvt(i, j), cvt(i, j-1), abs(b[i][j] - b[i][j-1])};
                g.push_back(nxt);
            }
        }
    }
    sort(g.begin(), g.end(), cmpe);
    fill(sz, sz+N*M, 1);
    iota(par, par+N*M, 0);
    for(edge i : g){
        un(i.u, i.v, i.d);
    }
    cout << ans << endl;
    return 0;
}


