/*
ID: sireric1
LANG: C++11
TASK: agrinet
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    int N; cin >> N;
    int adj[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
        }
    }
    bool isTree[N];
    int dist[N];
    int src[N];
    vi graph[N];
    fill(isTree, isTree+N, false);
    fill(src, src+N, -1);
    fill(dist, dist+N, INT_MAX);
    isTree[0] = true;
    int prev = 0;
    int ans = 0;
    for(int i = 0; i < N-1; i++){
        int minN = INT_MAX;
        int minidx = 0;
        for(int j = 0; j < N; j++){
            if(!isTree[j] && adj[prev][j] < dist[j]){
                dist[j] = adj[prev][j];
                src[j] = prev;
            }
            if(!isTree[j] && dist[j] < minN){
                minN = dist[j];
                minidx = j;
            }
        }
        ans += adj[src[minidx]][minidx];
        prev = minidx;
        isTree[minidx] = true;
    }
    cout << ans << endl;
    return 0;
}


