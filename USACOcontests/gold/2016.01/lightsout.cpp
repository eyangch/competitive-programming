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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
    ll N; cin >> N;
    pii pts[200];
    for(ll i = 0; i < N; i++){
        cin >> pts[i].first >> pts[i].second;
    }
    ll dists[200];
    dists[0] = 0;
    for(ll i = 1; i < N; i++){
        dists[i] = dists[i-1] + abs((pts[i].first - pts[i-1].first) + (pts[i].second - pts[i-1].second));
    }
    dists[N-1] = abs((pts[N-1].first - pts[0].first) + (pts[N-1].second - pts[0].second));
    for(ll i = N-2; i > 0; i--){
        if(dists[i+1] + abs((pts[i].first - pts[i+1].first) + (pts[i].second - pts[i+1].second)) >= dists[i]){
            break;
        }
        dists[i] = dists[i+1] + abs((pts[i].first - pts[i+1].first) + (pts[i].second - pts[i+1].second));
    }
    char lr[200];
    ll face = 0;
    for(ll i = 1; i <= N; i++){
        ll l = i-1;
        ll r = i+1;
        if(l < 0){
            l += N;
        }
        r %= N;
        if(pts[i].first != pts[l].first){
            if(signbit(pts[i].first - pts[l].first) == signbit(pts[r].second - pts[i].second)){
                lr[i] = 'L';
            }else{
                lr[i] = 'R';
            }
        }else{
            if(signbit(pts[i].second - pts[l].second) == signbit(pts[r].first - pts[i].first)){
                lr[i] = 'R';
            }else{
                lr[i] = 'L';
            }
        }
    }
    multiset<vi> strs;
    vi add;
    for(ll i = 1; i < N; i++){
        add.clear();
        add.push_back(lr[i]);
        for(ll j = 0; i+j < N; j++){
            if(j > 0){
                ll len = abs((pts[i+j].second - pts[i+j-1].second) + (pts[i+j].first - pts[i+j-1].first));
                if((i+j) == N){
                    len = -123456;
                }
                add.push_back(len);
                add.push_back(lr[i+j]);
            }
            strs.insert(add);
        }
    }
    ll ans = 0;
    for(ll i = 1; i < N; i++){
        ll tlen = 0;
        ll flen = 0;
        add.clear();
        add.push_back(lr[i]);
        for(ll j = 0; i+j < N; j++){
            if(j > 0){
                ll len = abs((pts[i+j].second - pts[i+j-1].second) + (pts[i+j].first - pts[i+j-1].first));
                if((i+j) == N){
                    len = -123456;
                }
                add.push_back(len);
                flen += len;
                add.push_back(lr[i+j]);
            }
            ll occ = strs.count(add);
            assert(occ > 0);
            if(strs.count(add) == 1){
                tlen = j;
                break;
            }
        }
        ans = max(ans, flen + dists[(i+tlen)%N] - dists[i]);
    }
    cout << ans << endl;
    return 0;
}


