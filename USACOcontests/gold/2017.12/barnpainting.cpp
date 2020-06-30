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
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    const ll MOD = 1e9+7;
    ll N, K; cin >> N >> K;
    vector<ll> graph[N];
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);   
    }
    bool ok[N][3];
    fill(ok[0], ok[N-1] + 3, true);
    for(int i = 0; i < K; i++){
        int b, c; cin >> b >> c;
        for(int j = 0; j < 3; j++){
            if(j != c-1){
                ok[b-1][j] = false;
            }
        }
    }
    ll depth[N];
    vi revdepth[N];
    fill(depth, depth + N, -1);
    stack<pii> dfs_depth;
    dfs_depth.push(pii(0, 0));
    while(!dfs_depth.empty()){
        pii idx = dfs_depth.top();
        dfs_depth.pop();
        if(depth[idx.first] != -1){
            continue;
        }
        depth[idx.first] = idx.second;
        revdepth[idx.second].push_back(idx.first);
        for(int i : graph[idx.first]){
            dfs_depth.push(pii(i, idx.second + 1));
        }
    }
    ll pb[N][3];
    for(int i = N-1; i >= 0; i--){
        for(int j : revdepth[i]){
            vi children;
            for(int k = 0; k < 3; k++){
                pb[j][k] = ok[j][k];
            }
            for(int k : graph[j]){
                if(depth[k] > i){
                    children.push_back(k);
                }
            }
            for(int k : children){
                for(int l = 0; l < 3; l++){
                    int mul = 0;
                    for(int m = 0; m < 3; m++){
                        if(m == l) continue;
                        mul += pb[k][m];
                    }
                    pb[j][l] *= mul;
                    pb[j][l] %= MOD;
                }
            }
        }
    }
    cout << (pb[0][0] + pb[0][1] + pb[0][2]) % MOD << endl;
    return 0;
}


