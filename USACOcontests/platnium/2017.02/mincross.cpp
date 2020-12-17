#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define endl "\n"
#define int ll

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

void setIO(string s){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(s != ""){
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}

int N;
int a[100000], b[100000];
int mp[100000];
int dv[100000];

signed main(){
    setIO("mincross");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a[i]--;
        mp[a[i]] = i;
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
        b[i]--;
        dv[b[i]] = (N-1) - 2 * i;
    }
    oset prev;
    int inv = 0;
    for(int i = N-1; i >= 0; i--){
        inv += prev.order_of_key(mp[b[i]]);
        prev.insert(mp[b[i]]);
    }
    int ans = inv;
    for(int i = 0; i < N; i++){
        inv += dv[a[i]];
        ans = min(ans, inv);
    }
    for(int i = 0; i < N; i++){
        inv += (N-1) - 2 * mp[b[i]];
        ans = min(ans, inv);
    }
    cout << ans << endl;
    return 0;
}


