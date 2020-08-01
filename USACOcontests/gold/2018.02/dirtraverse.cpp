#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll dfscnt(ll N, vi (&graph)[100000], ll idx, ll (&fcnt)[100000]){
    ll ret = 0;
    for(ll i : graph[idx]){
        ret += dfscnt(N, graph, i, fcnt);
    }
    fcnt[idx] = max(1LL, ret);
    return max(1LL, ret);
}

ll dfs(ll N, vi (&graph)[100000], ll idx, ll (&lens)[100000], ll (&fcnt)[100000], ll (&ans)[100000], ll prnt){
    ll delta = 0;
    if(prnt != -1){
        delta += 3 * (fcnt[0] - fcnt[idx]);
        delta -= lens[idx] * fcnt[idx];
        delta += ans[prnt];
    }
    ans[idx] = delta;
    ll ret = delta;
    for(ll i : graph[idx]){
        ret = min(ret, dfs(N, graph, i, lens, fcnt, ans, idx));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    ll N; cin >> N;
    vi graph[100000];
    ll lengths[100000];
    for(ll i = 0; i < N; i++){
        string fname; cin >> fname;
        lengths[i] = (ll)fname.length()+1;
        ll m; cin >> m;
        for(ll j = 0; j < m; j++){
            ll child; cin >> child;
            graph[i].push_back(child-1);
        }
        if(m == 0){
            lengths[i]--;
        }
    }
    ll fcnt[100000];
    dfscnt(N, graph, 0, fcnt);
    ll ans[100000];
    ll mindel = dfs(N, graph, 0, lengths, fcnt, ans, -1);
    ll bcost = 0;
    for(ll i = 1; i < N; i++){
        bcost += lengths[i] * fcnt[i];
    }
    cout << bcost+mindel << endl;
    return 0;
}


