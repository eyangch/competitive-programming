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

ll calc_score(pii a, int y){
    return (1000 * a.second - y * a.first);
}

ll works(int N, int W, pii wt[250], int y){
    ll dp[W+1];
    fill(dp, dp+W+1, LLONG_MIN);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        ll score = calc_score(wt[i], y);
        ll tmpdp[W+1];
        copy(dp, dp+W+1, tmpdp);
        for(int j = 0; j < W+1; j++){
            if(dp[j] == LLONG_MIN){
                continue;
            }
            if(j + wt[i].first >= W){
                tmpdp[W] = max(tmpdp[W], dp[j] + score);
            }else{
                tmpdp[j+wt[i].first] = max(tmpdp[j+wt[i].first], dp[j] + score);
            }
        }
        copy(tmpdp, tmpdp+W+1, dp);
    }
    return dp[W];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout); 
    ll N, W; cin >> N >> W;
    pii wt[250];
    for(int i = 0; i < N; i++){
        cin >> wt[i].first >> wt[i].second;
    }
    int lo = 0;
    int hi = 10000000;
    ll mid = 0;
    while(lo < hi){
        mid = (lo + hi) / 2;
        ll ok = works(N, W, wt, mid);
        if(ok < 0){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    while(works(N, W, wt, mid) > 0) mid++;
    while(works(N, W, wt, mid) < 0) mid--;
    cout << mid << endl;
    return 0;
}


