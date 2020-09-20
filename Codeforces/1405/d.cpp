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

int dfs(int N, vi (&graph)[100000], int idx, int par, int &mdist){
    int mx = 0, mx2 = 0;
    if(par != -1 && (int)graph[idx].size() == 1){
        return 0;
    }
    for(int i : graph[idx]){
        if(i == par) continue;
        int x = dfs(N, graph, i, idx, mdist) + 1;
        if(x >= mx){
            mx2 = mx;
            mx = x;
        }else if(x > mx2){
            mx2 = x;
        }
    }
    mdist = max(mdist, mx+mx2);
    return mx;
}

void dfs2(int N, vi (&graph)[100000], int idx, int par, int d, int (&dist)[100000]){
    dist[idx] = d;
    for(int i : graph[idx]){
        if(i == par) continue;
        dfs2(N, graph, i, idx, d+1, dist);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    int dist[100000];
    vi graph[100000];
    for(int tc = 1; tc <= T; tc++){
        int N, A, B, DA, DB; cin >> N >> A >> B >> DA >> DB;
        for(int i = 0; i < N; i++){
            graph[i].clear();
            dist[i] = 0;
        }
        for(int i = 0; i < N-1; i++){
            int u, v; cin >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        int mdist = 0;
        dfs(N, graph, 0, -1, mdist);
        DA = min(DA, mdist);
        DB = min(DB, mdist);
        dfs2(N, graph, A-1, -1, 0, dist);
        if(DA*2 >= DB || dist[B-1] <= DA){
            cout << "Alice" << endl;   
        }else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}


