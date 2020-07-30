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

int dp[248][60];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    int N; cin >> N;
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    fill(dp[0], dp[N-1]+60, -1);
    for(int i = 0; i < N; i++){
        dp[i][a[i]] = i;
    }
    int ans = 0;
    for(int k = 0; k < 60; k++){
        for(int i = 0; i < N; i++){
            if(a[i] >= k){
                continue;
            }
            int sec1 = dp[i][k-1];
            //cout << "I: " << i << "  K: " << k << " " << sec1 << endl;
            if(sec1 == -1 || sec1 == N-1) continue;
            int sec2 = dp[sec1+1][k-1];
            if(sec2 == -1) continue;
            dp[i][k] = sec2;
            ans = k;
        }
    }
    cout << ans << endl;
    return 0;
}


