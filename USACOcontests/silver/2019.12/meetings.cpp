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
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    ll N, L; cin >> N >> L;
    vi cows[2]; // x, weight (array = delta 0(left), 1(right))
    pii allcows[N];
    ll wT = 0;
    for(ll i = 0; i < N; i++){
        ll a, b, c; cin >> a >> b >> c;
        wT += a;
        c = (c+1)/2;
        cows[c].push_back(b);
        allcows[i] = pii(b, a);
    }
    sort(cows[0].begin(), cows[0].end());
    sort(cows[1].begin(), cows[1].end());
    sort(allcows, allcows+N);
    ll l = 0;
    ll r = (ll)cows[1].size() - 1;
    ll l0 = 0;
    ll r0 = N-1;
    ll T = 0;
    ll cwT = 0;
    while(cwT * 2 < wT){
        bool goL = false;
        if(r < 0)
            goL = true;
        else if(l >= (ll)cows[0].size())
            goL = false;
        else if(cows[0][l] > L - cows[1][r]){
            goL = false;
        }else{
            goL = true;
        }
        if(goL){
            T = cows[0][l];
            cwT += allcows[l0].second;
            l++;
            l0++;
        }else{
            T = L - cows[1][r];
            cwT += allcows[r0].second;
            r--;
            r0--;
        }
    }
    ll ans = 0;
    for(ll i : cows[1]){
        ans += upper_bound(cows[0].begin(), cows[0].end(), i+2*T) - upper_bound(cows[0].begin(), cows[0].end(), i);
    }
    cout << ans << endl;
    return 0;
}


