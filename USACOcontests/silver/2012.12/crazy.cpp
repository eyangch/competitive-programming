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
ostream &operator <<(ostream &os, unordered_map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll CCW(pii a, pii b, pii c){
    ll x = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}

bool isct(pair<pii, pii> a, pair<pii, pii> b){
    ll ccw1 = CCW(a.first, a.second, b.first);
    ll ccw2 = CCW(a.first, a.second, b.second);
    ll ccw3 = CCW(b.first, b.second, a.first);
    ll ccw4 = CCW(b.first, b.second, a.second);
    //cout << a << "   " << b << endl;
    //cout << ccw1 << " " << ccw2 << " " << ccw3 << " " << ccw4 << endl;
    return (ccw1 != ccw2 && ccw3 != ccw4);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
    ll N, C; cin >> N >> C;
    pair<pii, pii> f[N];
    for(ll i = 0; i < N; i++){
        cin >> f[i].first.first >> f[i].first.second >> f[i].second.first >> f[i].second.second;
    }
    ll polyID[N];
    bool vis[N];
    ll polies = 0;
    fill(vis, vis+N, false);
    for(ll i = 0; i < N; i++){
        if(vis[i]) continue;
        ll idx = i;
        while(!vis[idx]){
            polyID[idx] = polies;
            vis[idx] = true;
            for(ll j = 0; j < N; j++){
                if(!vis[j] && (f[idx].first == f[j].first || f[idx].first == f[j].second || f[idx].second == f[j].first || f[idx].second == f[j].second)){
                    idx = j;
                    break;
                }
            }
        }
        polies++;
    }
    pii cows[C];
    for(ll i =0; i < C;i++){
        cin >> cows[i].first >> cows[i].second;
    }
    bitset<1000> cbits[C];
    for(ll i = 0; i < C; i++){
        pii p1 = cows[i];
        pii p2 = pii(p1.first+1, 10000000);
        pair<pii, pii> line = make_pair(p1, p2);
        for(ll j = 0; j < N;j++){
            if(isct(line, f[j])){
                //cout << line << "    " << f[j] << endl;
                cbits[i].flip(polyID[j]);
            }
        }
    }
    //cout << isct(f[1], make_pair(pii(8, 3), pii(9, 1000000))) << endl;
    unordered_map<bitset<1000>, ll> com;
    for(ll i = 0; i < C; i++){
        com[cbits[i]]++;
    }
    //cout << com << endl;
    ll ans = 0;
    for(auto it = com.begin(); it != com.end(); it++){
        ans = max(ans, it -> second);
    }
    cout << ans << endl;
    return 0;
}


