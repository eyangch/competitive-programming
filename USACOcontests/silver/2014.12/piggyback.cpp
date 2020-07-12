#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

void cdist(ll N, ll start, vi (&graph)[40000], ll (&dist)[40000]){
    fill(dist, dist+N, INT_MAX);
    queue<pii> bfs;
    bool vis[40000];
    fill(vis, vis+N, false);
    bfs.push(pii(start, 0));
    while(!bfs.empty()){
        ll idx = bfs.front().first, d = bfs.front().second;
        bfs.pop();
        if(vis[idx]) continue;
        vis[idx] = true;
        dist[idx] = d;
        for(ll i : graph[idx]){
            bfs.push(pii(i, d+1));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    ll B, E, P, N, M; cin >> B >> E >> P >> N >> M;
    vi graph[40000];
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);   
    }
    ll dist_bessie[40000], dist_elsie[40000], dist_barn[40000];
    cdist(N, 0, graph, dist_bessie);
    cdist(N, 1, graph, dist_elsie);
    cdist(N, N-1, graph, dist_barn);
    ll ans = dist_bessie[N-1] * B + dist_elsie[N-1] * E;
    for(int i = 0; i < N; i++){
        ans = min(ans, dist_bessie[i] * B + dist_elsie[i] * E + dist_barn[i] * P);
    }
    cout << ans << endl;
    return 0;
}


