#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

int N, X;
int c[100];
int dp[1000001];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    sort(c, c+N);
    dp[0] = 1;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < N; j++){
            if(i + c[j] > X) break;
            dp[i+c[j]] = (dp[i+c[j]] + dp[i]) % MOD;
        }
    }
    cout << dp[X] << endl;
    return 0;
}


