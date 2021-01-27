#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int N;
ll A, B, MOD;
set<pii> s;

ll gcdf(ll a, ll b){
    return (b == 0 ? a : gcdf(b, a%b));
}

void upd(ll l, ll r){
    auto it = s.upper_bound({l, LLONG_MAX});
    vector<pii> rm;
    if(it != s.begin()){
        it--;
        if(it -> second >= r){
            return;
        }
        if(it -> second >= l){
            l = it -> first;
            rm.push_back(*it);
        }
        it++;
    }
    for(; it != s.end(); it++){
        if(it -> first > r) break;
        l = min(l, it -> first);
        r = max(r, it -> second);
        rm.push_back(*it);
    }
    for(pii i : rm){
        s.erase(i);
    }
    s.insert({l, r});
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> A >> B;
    __int128 mp = (__int128)(A / gcdf(A, B+1)) * B;
    MOD = (mp > 1e18 ? 1e18+5 : (ll)mp);
    for(int i = 0; i < N; i++){
        ll l, r; cin >> l >> r;
        if(r - l + 1 >= MOD){
            upd(0, MOD-1);
        }
        l %= MOD, r %= MOD;
        if(l > r){
            upd(l, MOD-1);
            upd(0, r);
        }else{
            upd(l, r);
        }
    }
    ll ans = 0;
    for(pii i : s){
        ans += i.se - i.fi + 1;
    }
    cout << ans << endl;
}
