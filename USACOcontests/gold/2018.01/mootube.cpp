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

int find(int u, int (&par)[100000]){
    if(par[u] == u){
        return u;
    }
    par[u] = find(par[u], par);
    return par[u];
}

void un(int u, int v, int (&par)[100000], int (&sz)[100000]){
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
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int N, Q; cin >> N >> Q;
    vector<pair<int, pii>> edges;
    for(int i = 0; i < N-1; i++){
        int u, v, r; cin >> u >> v >> r;
        edges.push_back(make_pair(r, pii(u-1, v-1)));   
    }
    sort(edges.begin(), edges.end(), greater<pair<int, pii>>());
    pair<pii, int> query[Q];
    for(int i = 0; i < Q; i++){
        cin >> query[i].first.first >> query[i].first.second;
        query[i].first.second--;
        query[i].second = i;
    }
    sort(query, query+Q, greater<pair<pii, int>>());
    int par[100000], sz[100000];
    for(int i = 0; i < N; i++){
        par[i] = i;
        sz[i] = 1;
    }
    int edgePtr = 0;
    int ans[Q];
    for(int i = 0; i < Q; i++){
        int ki = query[i].first.first, vi = query[i].first.second, idx = query[i].second;
        while(edgePtr < N && edges[edgePtr].first >= ki){
            un(edges[edgePtr].second.first, edges[edgePtr].second.second, par, sz);
            edgePtr++;
        }
        ans[idx] = sz[find(vi, par)]-1;
    }
    for(int i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}


