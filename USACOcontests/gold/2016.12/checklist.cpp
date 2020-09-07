#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll dp[1005][1005][2];

ll dist2(pii a, pii b){
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    ll H, G; cin >> H >> G;
    pii h[H], g[G];
    for(ll i = 0; i < H; i++){
        cin >> h[i].first >> h[i].second;   
    }
    for(ll i = 0; i < G; i++){
        cin >> g[i].first >> g[i].second;
    }
    fill(dp[0][0], dp[1004][1004]+2, 1e15);
    dp[1][0][0] = 0;
    for(ll i = 0; i <= H; i++){
        for(ll j = 0; j <= G; j++){
            if(i > 1){
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + dist2(h[i-2], h[i-1]));
            }
            if(j > 1){
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + dist2(g[j-2], g[j-1]));
            }
            if(i > 0 && j > 0){
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + dist2(g[j-1], h[i-1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + dist2(h[i-1], g[j-1]));
            }
        }
    }
    cout << dp[H][G][0] << endl;
    return 0;
}


