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

void bfs(int N, vi graph[200000], int src, int (&dist)[200000]){
    queue<pii> q;
    fill(dist, dist+N, INT_MAX);
    q.push(pii(0, src));
    while(!q.empty()){
        pii lst = q.front();
        q.pop();
        if(dist[lst.second] != INT_MAX){
            continue;
        }
        dist[lst.second] = lst.first;
        for(int i : graph[lst.second]){
            q.push(pii(lst.first+1, i));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    int spec[K];
    for(int i = 0; i < K; i++){
        cin >> spec[i];
        spec[i]--;
    }
    vi graph[200000];
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    int dist1[200000], dist2[200000];
    bfs(N, graph, 0, dist1);
    bfs(N, graph, N-1, dist2);
    pii d1d2[K];
    for(int i = 0; i < K; i++){
        d1d2[i] = pii(dist1[spec[i]] - dist2[spec[i]], spec[i]);
    }
    sort(d1d2, d1d2+K);
    int ans = 0;
    int maxd1 = dist1[d1d2[0].second];
    for(int i = 1; i < K; i++){
        ans = max(ans, maxd1 + dist2[d1d2[i].second]+1);
        maxd1 = max(maxd1, dist1[d1d2[i].second]);
    }
    cout << min(ans, dist1[N-1]) << endl;
    return 0;
}


