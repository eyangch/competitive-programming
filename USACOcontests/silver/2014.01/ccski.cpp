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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int M, N; cin >> M >> N; // M AND N ARE FLIPPED uh oh
    vector<pii> graph[N*M];
    int slopes[M][N];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> slopes[i][j];
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            for(int dir = 0; dir < 4; dir++){
                int nx = i+dx[dir], ny = j+dy[dir];
                if(nx < 0 || nx >= M || ny < 0 || ny >= N){
                    continue;
                }
                int d = abs(slopes[i][j] - slopes[nx][ny]);
                graph[N * i + j].push_back(pii(N * nx + ny, d));
            }
        }
    }
    bool wp[N*M];
    int wpN = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> wp[i * N + j];
            if(wp[i * N + j]){
                wpN++;
            }
        }
    }
    int src = 0;
    for(; src < N*M; src++){
        if(wp[src]) break;
    }
    int ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    bool vis[N*M];
    fill(vis, vis+N*M, false);
    pq.push(pii(0, src));
    while(!pq.empty()){
        pii lst = pq.top();
        pq.pop();
        if(vis[lst.second]){
            continue;
        }
        vis[lst.second] = true;
        ans = max(ans, lst.first);
        wpN -= wp[lst.second];
        if(!wpN){
            break;
        }
        for(pii i : graph[lst.second]){
            pq.push(pii(i.second, i.first));
        }
    }
    cout << ans << endl;
    return 0;
}


