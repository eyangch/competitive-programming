#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll N, M, T;
ll c[10000];
ll pass_through[10000];
vector<pii> graph[10000];
ll dist[10000];
bool vis[10000];

void dfs(int idx, int acc){
    ll pass = acc;
    if(!vis[idx]){
        pass += c[idx];
    }
    pass_through[idx] += pass;
    if(idx == 0) return;
    vis[idx] = true;
    ll minN = INT_MAX;
    ll minidx = 0;
    for(pii i : graph[idx]){
        if(dist[i.first] + i.second < minN || (dist[i.first] + i.second == minN && i.first < minidx)){
            minN = dist[i.first] + i.second;
            minidx = i.first;
        }
    }
    dfs(minidx, pass);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    cin >> N >> M >> T;
    for(int i = 0; i < N; i++) cin >> c[i];
    for(int i = 0; i < M; i++){
        ll a, b, t; cin >> a >> b >> t;
        graph[a-1].push_back(pii(b-1, t));
        graph[b-1].push_back(pii(a-1, t));
    }
    fill(dist, dist+N, INT_MAX);
    fill(vis, vis+N, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[0] = 0;
    pq.push(pii(dist[0], 0));
    while(!pq.empty()){
        pii lst = pq.top();
        pq.pop();
        for(pii i : graph[lst.second]){
            if(dist[i.first] > dist[lst.second] + i.second){
                dist[i.first] = dist[lst.second] + i.second;
                pq.push(pii(dist[i.first], i.first));
            }
        }
    }
    fill(pass_through, pass_through+N, 0);
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, pass_through[i] * (dist[i] - T));
    }
    cout << ans << endl;
    return 0;
}


