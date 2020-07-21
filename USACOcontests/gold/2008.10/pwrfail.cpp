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
    int N, W;
    double M;
    cin >> N >> W >> M;
    double x[N], y[N];
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    double adj[N][N];
    fill(adj[0], adj[N-1]+N, LLONG_MAX);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            if(dist <= M){
                adj[i][j] = dist;
            }
        }
    }
    for(int i = 0; i < W; i++){
        int pi, pj; cin >> pi >> pj;
        adj[pi-1][pj-1] = adj[pj-1][pi-1] = 0;
    }
    double dist[N];
    fill(dist, dist+N, LLONG_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 0));
    dist[0] = 0;
    while(!pq.empty()){
        pii lst = pq.top();
        pq.pop();
        for(int i = 0; i < N; i++){
            if(dist[i] > dist[lst.second] + adj[lst.second][i]){
                dist[i] = dist[lst.second] + adj[lst.second][i];
                pq.push(pii(dist[i], i));
            }
        }
    }
    if(dist[N-1] == LLONG_MAX){
        cout << -1 << endl;
    }else{
        cout << (int)(1000 * dist[N-1]) << endl;
    }
    return 0;
}


