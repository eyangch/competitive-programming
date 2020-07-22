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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dij(int N, vector<pii> graph[1600], int src){
    int mdist = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int dist[N*N];
    bool vis[N*N];
    fill(dist, dist+N*N, INT_MAX);
    fill(vis, vis+N*N, false);
    dist[src] = 0;
    pq.push(pii(dist[src], src));
    while(!pq.empty()){
        pii lst = pq.top();
        pq.pop();
        if(vis[lst.second]){
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
    for(int i = 0; i < N * N; i++){
        mdist = max(mdist, dist[i]);
    }
    return mdist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout);
    int N, A, B; cin >> N >> A >> B;
    vector<pii> graph[1600];
    string farm[N];
    for(int i = 0; i < N; i++){
        cin >> farm[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int dir = 0; dir < 4; dir++){
                int nx = i+dx[dir], ny = j+dy[dir];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N){
                    continue;
                }
                int d = A;
                if(farm[i][j] != farm[nx][ny]){
                    d = B;
                }
                graph[N * i + j].push_back(pii(N * nx + ny, d));
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N*N; i++){
        ans = max(ans, dij(N, graph, i));
    }
    cout << ans << endl;
    return 0;
}


