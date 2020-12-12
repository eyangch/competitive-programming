#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"
#define int ll

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

void setIO(string s){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(s != ""){
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}

int N, M;
vector<pii> graph[100000];
int dist[100000];

void dij(int src){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    bool vis[N];
    fill(dist, dist+N, LLONG_MAX);
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

signed main(){
    setIO("");
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v, d; cin >> u >> v >> d;
        graph[u-1].push_back(pii(v-1, d));
    }
    dij(0);
    for(int i = 0; i < N; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}


