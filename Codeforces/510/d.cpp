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

void dij(int N, vector<pii> graph[512], int src, int (&dist)[512], int sdist){
    bool vis[N];
    fill(dist, dist+N, INT_MAX);
    fill(vis, vis+N, false);
    dist[src] = sdist;
    for(int i = 0; i < N-1; i++){
        int u = 0, minu = INT_MAX;
        for(int j = 0; j < N; j++){
            if(!vis[j] && dist[j] < minu){
                u = j;
                minu = dist[j];
            }
        }
        //cout << u << " " << dist[u] << endl;
        vis[u] = true;
        if(dist[u] != INT_MAX){
            for(pii j : graph[u]){
                dist[j.first] = min(dist[j.first], dist[u] + j.second);
            }
        }
    }
}

void pfac(int x, vi &pf){
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            pf.push_back(i);
        }
        while(x % i == 0){
            x /= i;
        }
    }
    if(x > 1){
        pf.push_back(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    int l[300], c[300];
    for(int i = 0; i < N; i++){
        cin >> l[i];   
    }
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    int ans = INT_MAX;
    for(int i = 0; i < N; i++){
        vi pf;
        pfac(l[i], pf);
        int orig = 0;
        for(int j = 0; j < (int)pf.size(); j++){
            orig |= 1 << j;
        }
        //cout << orig << endl;
        vector<pii> graph[512];
        for(int j = 0; j < N; j++){
            int cur = 0;
            for(int k = 0; k < (int)pf.size(); k++){
                if(l[j] % pf[k] == 0){
                    cur |= 1 << k;
                }
            }
            for(int k = 0; k < 512; k++){
                graph[k].push_back(pii(k&cur, c[j]));
            }
        }
        int dist[512];
        for(int j = 0; j <= orig; j++){
            //cout << graph[j] << endl;
        }
        dij(orig+1, graph, orig, dist, c[i]);
        ans = min(ans, dist[0]);
        for(int j = 0; j < orig+1; j++){
            //cout << j << " " << dist[j] << endl;
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}


