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

int N;
pii mov[200000];
int dp[200000];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> mov[i].s >> mov[i].f;
    }
    sort(mov, mov+N);
    dp[0] = 1;
    for(int i = 1; i < N; i++){
        dp[i] = dp[i-1];
        int idx = upper_bound(mov, mov+N, pii(mov[i].s, 1e9)) - mov;
        idx--;
        if(idx < 0){
            continue;
        }
        dp[i] = max(dp[i], dp[idx] + 1);
    }
    cout << dp[N-1] << endl;
    return 0;
}


