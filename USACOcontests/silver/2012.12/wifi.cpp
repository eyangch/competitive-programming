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
    freopen("wifi.in", "r", stdin);
    freopen("wifi.out", "w", stdout);
    int N, A, B; cin >> N >> A >> B;
    A *= 2;
    int cows[2000];
    for(int i = 0; i < N; i++){
        cin >> cows[i];   
    }
    sort(cows, cows+N);
    int dp[2000];
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        dp[i] = INT_MAX;
        for(int j = 0; j < i; j++){
            dp[i] = min(dp[i], dp[j] + A + B * (cows[i-1] - cows[j]));
        }
    }
    cout << dp[N]/2;
    if(dp[N] % 2){
        cout << ".5";
    }
    cout << endl;
    return 0;
}


