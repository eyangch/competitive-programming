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

int N, adj[400][400], dp[400];
pii p[401];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p+N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
        }
    }
    fill(dp, dp+N, INT_MIN);
    for(int i = 0; i < N; i++){
        if(adj[0][p[i].second] <= p[i].first){
            dp[p[i].second] = 1;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(p[j].first + adj[p[j].second][p[i].second] <= p[i].first){
                dp[p[i].second] = max(dp[p[i].second], dp[p[j].second]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(dp[p[i].second], ans);
    }
    cout << ans << endl;
    return 0;
}


