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
    freopen("buffet.in", "r", stdin);
    freopen("buffet.out", "w", stdout);
    int N, E; cin >> N >> E;
    pii qual[N];
    vi graph[N];
    for(int i = 0; i < N; i++){
        cin >> qual[i].first;
        qual[i].second = i;
        int d; cin >> d;
        for(int j = 0; j < d; j++){
            int v; cin >> v;
            graph[i].push_back(v-1);
        }
    }
    sort(qual, qual+N);
    int sortid[N];
    for(int i = 0; i < N; i++){
        sortid[qual[i].second] = i;
    }
    ll dp[N], dist[N];
    fill(dp, dp+N, 0);
    for(int i = 0; i < N; i++){
        //cout << qual[i].second << endl;
        fill(dist, dist+N, INT_MAX);
        queue<pii> bfs;
        bfs.push(pii(qual[i].second, 0));
        while(!bfs.empty()){
            int idx = bfs.front().first, d = bfs.front().second;
            bfs.pop();
            if(dist[sortid[idx]] != INT_MAX) continue;
            dist[sortid[idx]] = d;
            for(int j : graph[idx]){
                bfs.push(pii(j, d+1));
            }
        }
        for(int j = i; j >= 0; j--){
            dp[i] = max(dp[i], dp[j] - (E * dist[j]));
            //cout << j << " " << dp[j] << " | ";
        }//cout << endl;
        dp[i] += qual[i].first;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}


