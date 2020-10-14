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

int R, N;
int t[100001], x[100001], y[100001];
int mx[100001]; 
int dp[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> R >> N;
    fill(dp, dp+N+1, -1e9);
    t[0] = 0; x[0] = 1; y[0] = 1;
    for(int i = 1; i <= N; i++){
        cin >> t[i] >> x[i] >> y[i];
    }
    dp[0] = 0;
    mx[0] = dp[0];
    for(int i = 1; i <= N; i++){
        for(int j = i-1; j >= 0; j--){
            if(t[j] + 1000 <= t[i]){
                dp[i] = max(dp[i], mx[j]+1);
                break;
            }
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        mx[i] = max(mx[i-1], dp[i]);
    }
    cout << mx[N] << endl;
    return 0;
}


