#include <bits/stdc++.h>
#define f first
#define s second

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

int N, P[1001];
int dp[1001][1001][2];

int dfs(int l, int r, int side, bool prev){
    if(dp[l][r][side] > -1){
        return dp[l][r][side];
    }
    int active = N - (r - l);
    int ans = 1e9;
    if(!prev){
        ans = min(ans, active * (P[r] - P[l]) + dfs(l, r, !side, true));
    }
    if(side == 0 && l > 0){
        ans = min(ans, active * (P[l] - P[l-1]) + dfs(l-1, r, side, false));
    }
    if(side == 1 && r < N){
        ans = min(ans, active * (P[r+1] - P[r]) + dfs(l, r+1, side, false));
    }
    dp[l][r][side] = ans;
    return dp[l][r][side];
}

int main(){
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    P[N] = 0;
    sort(P, P+N+1);
    fill(dp[0][0], dp[1000][1000]+2, -1);
    dp[0][N][0] = dp[0][N][1] = 0;
    int zidx = lower_bound(P, P+N+1, 0) - P;
    cout << dfs(zidx, zidx, 0, false) << endl;
    return 0;
}


