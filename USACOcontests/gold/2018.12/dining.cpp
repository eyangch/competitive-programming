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

void dij(int N, vector<pii> graph[50000], int src, int (&dist)[50000]){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    bool vis[N];
    fill(dist, dist+N, INT_MAX);
    fill(vis, vis+N, false);
    dist[src] = 0;
    pq.push(pii(dist[src], src));
    while(!pq.empty()){
        pii lst = pq.top();
        pq.pop();
        if(vis[lst.second] && (lst.second != src || lst.first < dist[lst.second])){
            continue;
        }
        vis[lst.second] = true;
        for(pii i : graph[lst.second]){
            if(dist[i.first] > dist[lst.second] + i.second){
                dist[i.first] = dist[lst.second] + i.second;
                pq.push(pii(dist[i.first], i.first));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    int N, M, K; cin >> N >> M >> K;
    vector<pii> graph[50000];
    for(int i = 0; i < M; i++){
        int u, v, t; cin >> u >> v >> t;
        graph[u-1].push_back(pii(v-1, t));
        graph[v-1].push_back(pii(u-1, t));
    }
    int dista[50000];
    dij(N, graph, N-1, dista);
    for(int i = 0; i < K; i++){
        int idxp, yum; cin >> idxp >> yum;
        graph[N-1].push_back(pii(idxp-1, dista[idxp-1] - yum - 1));
    }
    int fdist[50000];
    dij(N, graph, N-1, fdist);
    for(int i = 0; i < N-1; i++){
        if(fdist[i] < dista[i]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}


