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
 
ll N, K;
ll a[100000];
ll dv[100000];
ll tdiv = 0;
set<pii> mx;

ll calc(ll num, ll divcnt){
    ll base = num / divcnt;
    ll np1 = num % divcnt;
    ll sq1 = base * base;
    ll sq2 = (base+1) * (base+1);
    return sq2 * np1 + sq1 * (divcnt - np1);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(ll i = 0; i < N; i++){
        cin >> a[i];
        dv[i] = 1;
        tdiv++;
        mx.insert(pii(calc(a[i], 1) - calc(a[i], 2), i));
    }
    while(tdiv < K){
        pii top = *mx.rbegin();
        mx.erase(top);
        dv[top.s]++;
        tdiv++;
        ll n1 = calc(a[top.s], dv[top.s]);
        ll n2 = calc(a[top.s], dv[top.s]+1);
        mx.insert(make_pair(n1 - n2, top.s));
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        //cout << dv[i] << endl;
        ll base = a[i] / dv[i];
        ll up1 = a[i] % dv[i];
        for(ll j = 0; j < up1; j++){
            ans += (base+1) * (base+1);
        }
        for(ll j = up1; j < dv[i]; j++){
            ans += base * base;
        }
    }
    cout << ans << endl;
    return 0;
}

