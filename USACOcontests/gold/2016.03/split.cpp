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
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ll N; cin >> N;
    pii c[N];
    ll minX = INT_MAX, maxX = 0, minY = INT_MAX, maxY = 0;
    for(ll i = 0; i < N; i++){
        cin >> c[i].first >> c[i].second;
        minX = min(minX, c[i].first);
        minY = min(minY, c[i].second);
        maxX = max(maxX, c[i].first);
        maxY = max(maxY, c[i].second);
    }
    ll origarea = (maxX - minX) * (maxY - minY);
    ll minarea = LLONG_MAX;
    for(ll i = 0; i < 2; i++){
        sort(c, c+N);
        ll minpfx[N], maxpfx[N];
        minpfx[N-1] = c[N-1].second;
        maxpfx[N-1] = c[N-1].second;
        for(ll j = N-2; j >= 0; j--){
            minpfx[j] = min(minpfx[j+1], c[j].second);
            maxpfx[j] = max(maxpfx[j+1], c[j].second);
        }
        ll runmin = INT_MAX, runmax = 0;
        for(ll j = 0; j < N-1; j++){
            runmin = min(runmin, c[j].second);
            runmax = max(runmax, c[j].second);
            ll b1 = (runmax - runmin) * (c[j].first - minX);
            ll b2 = (maxpfx[j+1] - minpfx[j+1]) * (maxX - c[j+1].first);
            minarea = min(minarea, b1+b2);
        }
        for(ll j = 0; j < N; j++){
            swap(c[j].first, c[j].second);
        }
        swap(minX, minY);
        swap(maxX, maxY);
    }
    //cout << origarea << " " << minarea << endl;
    cout << origarea - minarea << endl;
    return 0;
}


