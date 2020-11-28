#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"
#define int ll

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

int MOD = 998244353;

int N;
int k[1000000];
vi a[1000000];
int occ[1000001];

ll fexp(ll a, ll b){
    ll ans = 1;
    for(int i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> k[i];
        for(int j = 0; j < k[i]; j++){
            int x; cin >> x;
            a[i].push_back(x);
            occ[x]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < k[i]; j++){
            int cnum = occ[a[i][j]];
            int cden = N * k[i] % MOD * N % MOD;
            ans += cnum * fexp(cden, MOD-2) % MOD;
            ans %= MOD;
        }
    }
    //cout << num << " " << den << endl;
    //int inv = fexp(den, MOD-2);
    cout << ans << endl;
    return 0;
}


