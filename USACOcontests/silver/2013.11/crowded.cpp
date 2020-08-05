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
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout);
    ll N, D; cin >> N >> D;
    pii cows[N];
    for(ll i = 0; i < N; i++){
        cin >> cows[i].second >> cows[i].first;   
    }
    sort(cows, cows+N);
    multiset<ll> active;
    ll ptr = N-1;
    ll cnt = 0;
    for(ll i = N-1; i >= 0; i--){
        while(cows[i].first * 2 <= cows[ptr].first){
            active.insert(cows[ptr].second);
            ptr--;
        }
        auto left = active.lower_bound(cows[i].second - D);
        auto right = active.lower_bound(cows[i].second);
        //cout << cows[i] << " " << active << endl;
        //cout << cows[i] << "  " << (*left) << " " << (*right) << endl;
        if(left != active.end() && right != active.end() && (*left) <= cows[i].second && (*right) <= cows[i].second + D){
            cnt++;
            //cout << cows[i] << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}


