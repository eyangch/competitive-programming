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

bool b[1000][1000];
ll sec[1000][1000];
ll dist[1000][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M, T; cin >> N >> M >> T;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < M; j++){
            b[i][j] = (s[j] == '1');   
        }
    }
    fill(sec[0], sec[N-1]+M, -1);
    fill(dist[0], dist[N-1]+M, 0);
    queue<pair<pii, ll>> bfs2; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            queue<pii> bfs;
            bfs.push(pii(i, j));
            ll assigned = 0;
            while(!bfs.empty()){
                pii idx = bfs.front();
                bfs.pop();
                ll x = idx.first, y = idx.second;
                if(x < 0 || x >= N || y < 0 || y >= M || b[x][y] != b[i][j] || sec[x][y] != -1){
                    continue;
                }
                sec[x][y] = 0;
                assigned++;
                bfs.push(pii(x+1, y));
                bfs.push(pii(x-1, y));
                bfs.push(pii(x, y+1));
                bfs.push(pii(x, y-1));
            }
            if(assigned == 1){
                sec[i][j] = -1;
                dist[i][j] = LLONG_MAX;
            }else{
                bfs2.push(make_pair(pii(i+1, j), 1LL));
                bfs2.push(make_pair(pii(i-1, j), 1LL));
                bfs2.push(make_pair(pii(i, j+1), 1LL));
                bfs2.push(make_pair(pii(i, j-1), 1LL));
            }   
        }
    }
    while(!bfs2.empty()){
        pair<pii, ll> idx = bfs2.front();
        bfs2.pop();
        ll x = idx.first.first, y = idx.first.second, d = idx.second;
        if(x < 0 || x >= N || y < 0 || y >= M || dist[x][y] != LLONG_MAX){
            continue;
        }
        dist[x][y] = d;
        bfs2.push(make_pair(pii(x+1, y), d+1));
        bfs2.push(make_pair(pii(x-1, y), d+1));
        bfs2.push(make_pair(pii(x, y+1), d+1));
        bfs2.push(make_pair(pii(x, y-1), d+1));
    }
    for(int i = 0; i < T; i++){
        ll x, y, p; cin >> x >> y >> p;
        x--; y--;
        p -= (dist[x][y] > p ? p : dist[x][y]);
        cout << (p + b[x][y]) % 2 << endl;
    }
    return 0;
}


