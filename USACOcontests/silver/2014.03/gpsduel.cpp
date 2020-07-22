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

void dij(int N, vector<pii> graph[10000], int src, int (&dist)[10000]){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    bool vis[N];
    fill(dist, dist+N, INT_MAX);
    fill(vis, vis+N, false);
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
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("gpsduel.in", "r", stdin);
    freopen("gpsduel.out", "w", stdout);
    int N, M; cin >> N >> M;
    vector<pii> gps1[10000], gps2[10000], fj[10000];
    int dist1[10000], dist2[10000], distfj[10000];
    for(int i = 0; i < M; i++){
        int a, b, p, q; cin >> a >> b >> p >> q;
        gps1[b-1].push_back(pii(a-1, p));
        gps2[b-1].push_back(pii(a-1, q));
        fj[b-1].push_back(pii(a-1, 2));
    }
    dij(N, gps1, N-1, dist1);
    dij(N, gps2, N-1, dist2);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < (int)fj[i].size(); j++){
            if(dist1[i] == dist1[fj[i][j].first] - gps1[i][j].second){
                fj[i][j].second--;
            }
            if(dist2[i] == dist2[fj[i][j].first] - gps2[i][j].second){
                fj[i][j].second--;
            }
        }
    }
    dij(N, fj, N-1, distfj);
    cout << distfj[0] << endl;
    return 0;
}


