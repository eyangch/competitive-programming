#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N, K, M;
    cin >> N >> K >> M;
    string s[N];
    for(ll i = 0; i < N; i++){
        cin >> s[i];
    }
    ll cost[N];
    for(ll i = 0; i < N; i++){
        cin >> cost[i];
    }
    unordered_map<string, ll> cmin;
    for(ll i = 0; i < K; i++){
        ll x;
        cin >> x;
        ll syn[x], tmin = LLONG_MAX;
        for(ll j = 0; j < x; j++){
            cin >> syn[j];
            syn[j]--;
            tmin = min(tmin, cost[syn[j]]);
        }
        for(ll j = 0; j < x; j++){
            cmin.insert(make_pair(s[syn[j]], tmin));
        }
    }
    ll ans = 0;
    for(ll i = 0; i < M; i++){
        string word;
        cin >> word;
        ans += cmin[word];
    }
    cout << ans << endl;
    return 0;
}
