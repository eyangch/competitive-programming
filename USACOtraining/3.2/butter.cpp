/*
ID: sireric1
LANG: C++11
TASK: butter
*/

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

int dij(int P, int (&cows)[800], vector<pii> (&graph)[800], int src){
    int ret = 0;
    int dist[P];
    fill(dist, dist+P, INT_MAX/3);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push(pii(dist[src], src));
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
    for(int i = 0; i < P; i++) ret += cows[i] * dist[i];
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    int N, P, C; cin >> N >> P >> C;
    int cows[800];
    fill(cows, cows+N, 0);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        cows[x-1]++;
    }
    vector<pii> graph[800];
    for(int i = 0; i < C; i++){
        int u, v, l; cin >> u >> v >> l;
        graph[u-1].push_back(pii(v-1, l));
        graph[v-1].push_back(pii(u-1, l));
    }
    int ans = INT_MAX;
    for(int i = 0; i < P; i++){
        ans = min(ans, dij(P, cows, graph, i));
    }
    cout << ans << endl;
    return 0;
}


