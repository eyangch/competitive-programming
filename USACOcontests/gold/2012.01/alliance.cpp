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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const ll MOD = 1000000007;
    int N, M; cin >> N >> M;
    vi graph[N];
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    bool vis[N];
    fill(vis, vis+N, false);
    ll ans = 1;
    for(int i = 0; i < N; i++){
        if(vis[i]) continue;
        int nodes = 0;
        int edges = 0;
        queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty()){
            int idx = bfs.front();
            bfs.pop();
            if(vis[idx]) continue;
            vis[idx] = true;
            nodes++;
            edges += graph[idx].size();
            for(int j : graph[idx]){
                bfs.push(j);
            }
        }
        edges /= 2;
        if(nodes == edges){
            ans *= 2;
        }else{
            ans *= nodes;
        }
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}


