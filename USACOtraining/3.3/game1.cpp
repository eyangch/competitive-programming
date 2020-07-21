/*
ID: sireric1
LANG: C++11
TASK: game1
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
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    int N; cin >> N;
    int a[N];
    int dp[N][N];
    int total = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];   
        dp[i][i] = a[i];
        total += a[i];
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < N-i; j++){
            dp[j][i+j] = max(a[i+j] - dp[j][i+j-1], a[j] - dp[j+1][i+j]);
        }
    }
    int x = (total + dp[0][N-1]) / 2, y = total - x;
    cout << x << " " << y << endl;
    return 0;
}


