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

int dfsp(int N, int (&p)[100000], int (&h)[100000], vi (&graph)[100000], bool (&vis)[100000], int idx, int (&people)[100000]){
    if(vis[idx]) return 0;
    vis[idx] = true;
    people[idx] = p[idx];
    for(int i : graph[idx]){
        people[idx] += dfsp(N, p, h, graph, vis, i, people);
    }
    return people[idx];
}

int dfs(int N, int (&people)[100000], int (&p)[100000], int (&h)[100000], vi (&graph)[100000], bool (&vis)[100000], int idx, bool &ok){
    if(vis[idx]) return 0;
    vis[idx] = true;
    int lb = -p[idx];
    for(int i : graph[idx]){
        lb += dfs(N, people, p, h, graph, vis, i, ok);
    }
    if(h[idx] < lb || h[idx] > people[idx] || (int)abs(h[idx]) % 2 != people[idx] % 2){
        ok = false;
    }
    return h[idx];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N, M; cin >> N >> M;
        int p[100000], h[100000];
        for(int i = 0; i < N; i++){
            cin >> p[i];   
        }
        for(int i = 0; i < N; i++){
            cin >> h[i];
        }
        vi graph[100000];
        bool vis[100000];
        fill(vis, vis+N, false);
        for(int i = 0; i < N-1; i++){
            int u, v; cin >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        int people[100000];
        dfsp(N, p, h, graph, vis, 0, people);
        fill(vis, vis+N, false);
        bool ok = true;
        dfs(N, people, p, h, graph, vis, 0, ok);
        if(ok){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


