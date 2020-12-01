#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"
#define int ll

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

int MOD = 1e9+7;

int N, M, X, Y, K;
vector<pii> graph[1500];
vector<vi> len;
vi curr;
bool vis[1500];
vi starting;
int all_paths = 0;
int dp[2][2501];

ll fexp(ll a, ll b){
    ll ans = 1;
    for(int i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

void dfsfind(int id){
    if(vis[id]) return;
    vis[id] = true;
    starting.push_back(id);
    for(pii i : graph[id]){
        dfsfind(i.f);
    }
}

void dfs(int start, int id, int par, int d){
    for(pii i : graph[id]){
        if(i.f == par) continue;
        dfs(start, i.f, id, d + i.s);
    }
    if(id != start){
        curr.push_back(d);
    }
}

signed main(){
    freopen("mooriokart.in", "r", stdin);
    freopen("mooriokart.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> M >> X >> Y;
    for(int i = 0; i < M; i++){
        int a, b, d; cin >> a >> b >> d;
        graph[a-1].push_back(pii(b-1, d));
        graph[b-1].push_back(pii(a-1, d));
    }
    for(int i = 0; i < N; i++){
        if(vis[i]) continue;
        starting.clear();
        curr.clear();
        dfsfind(i);
        for(int j : starting){
            dfs(j, j, -1, 0);
        }
        sort(curr.begin(), curr.end());
        len.push_back(curr);
    }
    K = (int)len.size();
    int tN = 1;
    for(int i = 0; i < K; i++){
        tN = tN * len[i].size() % MOD;
    }
    all_paths = X * tN % MOD * K % MOD;
    for(int i = 0; i < K; i++){
        int ctN = tN * fexp(len[i].size(), MOD-2) % MOD;
        for(int j : len[i]){
            all_paths = (all_paths + ctN * j) % MOD;
        }
    }
    dp[1][0] = 1;
    for(int i = 0; i < K; i++){
        int a = i % 2;
        int b = !a;
        for(int j = Y-1; j >= 0; j--){
            dp[a][j] = 0;
            for(int k : len[i]){
                if(j - k - X < 0) break;
                dp[a][j] = (dp[a][j] + dp[b][j-k-X]) % MOD;
            }
        }
    }
    int ans = all_paths;
    for(int i = 0; i < Y; i++){
        ans = (ans - (i * dp[(K-1)%2][i] % MOD) + MOD) % MOD;
    }
    int fact = 1;
    for(int i = 1; i < K; i++){
        fact = fact * i % MOD;
    }
    cout << ans * fact % MOD * fexp(2, MOD-2) % MOD << endl;
    return 0;
}


