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

ll get(ll x, ll (&BIT)[200001]){
    ll sum = 0;
    for(; x > 0; x -= x&-x){
        sum += BIT[x];
    }
    return sum;
}

void upd(ll x, ll dv, ll N, ll (&BIT)[200001]){
    for(; x <= 2*N; x += x&-x){
        BIT[x] += dv;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout); 
    ll N; cin >> N;
    ll cows[2*N], start[N], BIT[200001];
    fill(start, start+N, -1);
    for(ll i = 0; i < 2*N; i++){
        cin >> cows[i];
        cows[i]--;
        if(start[cows[i]] < 0) start[cows[i]] = i;
    }
    fill(BIT, BIT+(2*N), 0);
    ll ans = 0;
    for(ll i = 0; i < 2*N; i++){
        if(start[cows[i]] == i){
            upd(i+1, 1, N, BIT);
        }else{
            upd(start[cows[i]]+1, -1, N, BIT);
            ans += get(i+1, BIT) - get(start[cows[i]]+1, BIT);
        }
        //cout <<i << " "  << start[cows[i]]<< " " << get(i+1, BIT) << " " << get(start[cows[i]]+1, BIT) << endl;
    }
    cout << ans << endl;
    return 0;
}


