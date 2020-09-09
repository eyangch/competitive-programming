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

ll MOD = 1e9+7;
ll N, cyclesz = -1, sz, visn[200000];
vi graph[200000];
bool vis[200000];

void dfs(int idx, int par, int x){
    if(vis[idx] && cyclesz >= 0) return;
    if(visn[idx] >= 0){
        cyclesz = x - visn[idx];
        return;
    }
    if(vis[idx]) return;
    sz++;
    vis[idx] = true;
    visn[idx] = x;
    bool p = false;
    for(int i : graph[idx]){
        if(i == par && !p){
            p = true;
            continue;
        }
        dfs(i, idx, x+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N; 
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        graph[i].push_back(x-1);
        graph[x-1].push_back(i);
    }
    fill(visn, visn+N, -1);
    ll ans = 1;
    for(int i = 0; i < N; i++){
        if(vis[i]) continue;
        cyclesz = -1;
        sz = 0;
        dfs(i, -1, 0);
        assert(cyclesz > 0);
        ll a = 1;
        for(int i = 0; i < cyclesz; i++){
            a *= 2;
            a %= MOD;
        }
        a -= 2;
        a = (a+MOD)%MOD;
        for(int i = 0; i < sz - cyclesz; i++){
            a *= 2;
            a %= MOD;
        }
        ans *= a;
        ans %= MOD;
        //cout << cyclesz << " " << sz << " " << a << endl;
    }
    cout << ans << endl;
    return 0;
}


