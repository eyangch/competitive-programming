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

ll N, a[20], ans = LLONG_MAX, target = 0;

void dfs(ll idx, ll sum){
    if(idx == N){
        ll osum = target - sum;
        ans = min(ans, abs(osum - sum));
        return;
    }
    if(idx > 0){
        sum += a[idx];
    }
    for(int i = idx+1; i <= N; i++){
        dfs(i, sum);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        target += a[i];
    }
    dfs(-1, 0);
    cout << ans << endl;
    return 0;
}


