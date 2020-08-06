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

struct edge{
    int d;
    pii p1;
    pii p2;
};

pii find(pii u, pii (&par)[500][500]){
    if(par[u.first][u.second] == u){
        return u;
    }
    par[u.first][u.second] = find(par[u.first][u.second], par);
    return par[u.first][u.second];
}

void un(pii u, pii v, pii (&par)[500][500], int (&sz)[500][500]){
    u = find(u, par);
    v = find(v, par);
    if(u == v){
        return;
    }
    if(sz[u.first][u.second] < sz[v.first][v.second]){
        par[u.first][u.second] = v;
        sz[v.first][v.second] += sz[u.first][u.second];
    }else{
        par[v.first][v.second] = u;
        sz[u.first][u.second] += sz[v.first][v.second];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    int N; cin >> N;
    int grid[N][N];
    for(int i = 0; i < N; i++){
        for(int j =0; j < N; j++){
            cin >> grid[i][j];   
        }
    }
    vector<edge> edges;
    edge nxt;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i > 0){
                nxt = {abs(grid[i][j] - grid[i-1][j]), pii(i, j), pii(i-1, j)};
                edges.push_back(nxt);
            }
            if(j > 0){
                nxt = {abs(grid[i][j] - grid[i][j-1]), pii(i, j), pii(i, j-1)};
                edges.push_back(nxt);
            }
        }
    }
    sort(edges.begin(), edges.end(), [](edge a, edge b){
        if(a.d == b.d){
            return make_pair(a.p1, a.p2) < make_pair(b.p1, b.p2);
        }
        return a.d < b.d;
    });
    /*for(edge i : edges){
        cout << i.d << "  " << i.p1 << "   " << i.p2 << endl;
    }*/
    pii par[500][500];
    for(int i = 0; i < N; i++){
        for(int j =0; j < N;j++){
            par[i][j] = pii(i, j);
        }
    }
    int sz[500][500];
    fill(sz[0], sz[N-1]+N, 1);
    for(edge i : edges){
        int d = i.d;
        pii p1 = i.p1, p2 = i.p2;
        un(p1, p2, par, sz);
        pii prnt = find(p1, par);
        int tsize = sz[prnt.first][prnt.second];
        if(tsize * 2 >= N * N){
            cout << d << endl;
            return 0;
        }
    }
    return 0;
}


