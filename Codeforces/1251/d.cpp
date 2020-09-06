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

ll ans = 0;
pii lr[200000];

bool cmp(pii a, pii b){
    return (pii(a.second, a.first) < pii(b.second, b.first));
}

bool works(ll N, ll S, ll mid){
    ll start = 0;
    sort(lr, lr+N, cmp);
    for(; start < N; start++){
        if(lr[start].second >= mid){
            break;
        }
        S -= lr[start].first;
    }
    if(N - start < (N+1)/2){
        return false;
    }
    sort(lr+start, lr+N);
    for(ll i = start; N - i > (N+1)/2; i++){
        S -= lr[i].first;
    }
    for(ll i = (N+1)/2-1; i < N; i++){
        S -= max(mid, lr[i].first);
    }
    return (S >= 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    for(ll tc = 1; tc <= T; tc++){
        ll N, S; cin >> N >> S;
        for(ll i = 0; i <N; i++){
            cin >> lr[i].first >> lr[i].second;
        }
        ll lo = 0;
        ll hi = 1e9;
        ll mid = 0;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(works(N, S, mid)){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        while(works(N, S, mid)){
            mid++;
        }
        while(!works(N, S, mid)){
            mid--;
        }
        cout << mid << endl;
    }
    return 0;
}


