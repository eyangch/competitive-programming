#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define endl "\n"

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

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
int N;
pii seg[100000];
int pow2[100000];
int dp = 1;

signed main(){
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> seg[i].f >> seg[i].s;
    }
    pow2[0] = 1;
    for(int i = 1; i < N; i++){
        pow2[i] = pow2[i-1] * 2 % MOD;
    }
    sort(seg, seg+N);
    oset ends;
    ends.insert(seg[0].s);
    for(int i = 1; i < N; i++){
        dp = (dp * 2 % MOD + pow2[ends.order_of_key(seg[i].f)]) % MOD;
        ends.insert(seg[i].s);
    }
    cout << dp << endl;
    return 0;
}


