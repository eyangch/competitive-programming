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

ll MOD = 1e9+7;

int N;
string s;
ll n11[100001];
ll n10[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    N = (int)s.length();
    n11[0] = n10[0] = 1;
    for(int i = 1; i < N; i++){
        n11[i] = (n11[i-1] * 10 + 1) % MOD;
        n10[i] = (n10[i-1] * 10) % MOD;
    }
    ll ans = 0;
    ll sum = 0;
    for(int i = N-1; i >= 0; i--){
        sum += ((ll)(s[i] - '0') * n10[N-1-i]);
        sum %= MOD;
        ans += sum * i;
        ans %= MOD;
    }
    ll sum2 = 0;
    for(int i = 0; i < N-1; i++){
        sum2 *= 10;
        sum2 += s[i] - '0';
        sum2 %= MOD;
        ans += n11[N-2-i] * sum2;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}


