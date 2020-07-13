/*
ID: sireric1
LANG: C++11
TASK: inflate
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
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    int M, N; cin >> M >> N; 
    int points[N], minutes[N];
    for(int i = 0; i < N; i++){
        cin >> points[i] >> minutes[i];
    }
    int dp[M+1];
    fill(dp, dp+M+1, 0);
    for(int i = 0; i <= M; i++){
        for(int j = 0; j < N; j++){
            if(minutes[j] <= i){
                dp[i] = max(dp[i], dp[i-minutes[j]] + points[j]);
            }
        }
    }
    cout << dp[M] << endl;
    return 0;
}


