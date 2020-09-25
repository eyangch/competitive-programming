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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for(int tc = 1; tc <= N; tc++){
        ll a, b; cin >> a >> b;
        ll ans = 1;
        for(int i = 0; i < 30; i++){
            if(b&(1<<i)){
                ans *= a;
            }
            a *= a;
            a %= MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}


