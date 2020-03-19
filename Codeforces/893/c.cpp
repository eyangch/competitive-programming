#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N, M;
    cin >> N >> M;
    ll gold[N];
    vector<ll> f[N];
    for(ll i = 0; i < N; i++){
        cin >> gold[i];
    }
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        f[a-1].push_back(b-1);
        f[b-1].push_back(a-1);
    }
    ll ans = 0;
    unordered_set<ll> been;
    for(ll i = 0; i < N; i++){
        if(been.find(i) != been.end()){
            continue;
        }
        ll add = gold[i];
        if(f[i].size() != 0){
            stack<ll> dfs;
            dfs.push(i);
            while(!dfs.empty()){
                ll idx = dfs.top();
                dfs.pop();
                if(been.find(idx) != been.end()){
                    continue;
                }
                been.insert(idx);
                add = min(add, gold[idx]);
                for(ll j : f[idx]){
                    dfs.push(j);
                }
            }

        }
        ans += add;
    }
    cout << ans << endl;
    return 0;
}
