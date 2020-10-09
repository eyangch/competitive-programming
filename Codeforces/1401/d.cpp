#include <bits/stdc++.h>
#define f first
#define s second

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

ll MOD = 1e9+7;
ll N, M, p[105000], children[105000];
vi graph[105000];

ll dfs(ll idx, ll par){
    ll c = 0;
    for(ll i : graph[idx]){
        if(i != par){
            c += dfs(i, idx);
        }
    }
    c++;
    children[idx] = c;
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    for(ll tc = 1; tc <= T; tc++){
        cin >> N;
        for(ll i = 0; i < N; i++){
            graph[i].clear();
        }
        for(ll i = 0; i < N-1; i++){
            ll u, v; cin >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        cin >> M;
        for(ll i = 0; i < M; i++){
            cin >> p[i];
        }
        sort(p, p+M);
        dfs(0, -1);
        vi trav;
        for(ll i = 0; i < N; i++){
            for(ll j : graph[i]){
                if(children[i] > children[j]){
                    trav.push_back((N-children[j]) * children[j]);
                }
            }
        }
        sort(trav.begin(), trav.end());
        ll ptr = 0;
        ll ans = 0;
        while(M < (ll)trav.size() - ptr){
            ptr++;
        }
        for(ll i = 0; ptr + i < (ll)trav.size(); i++){
            trav[ptr+i] *= p[i];
            trav[ptr+i] %= MOD;
        }
        for(ll i = (ll)trav.size(); i < M; i++){
            trav[(ll)trav.size()-1] *= p[i];
            trav[(ll)trav.size()-1] %= MOD;
        }
        for(ll i : trav){
            ans += i;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}


