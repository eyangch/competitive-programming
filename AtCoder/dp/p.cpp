#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll MOD = 1e9+7;
int N;
vector<int> graph[100000];

pii dfs(int id, int par){
    pii ret = {1, 1};
    for(int i : graph[id]){
        if(i == par) continue;
        pii cur = dfs(i, id);
        ret.fi = ret.fi * (cur.fi + cur.se) % MOD;
        ret.se = ret.se * cur.fi % MOD;
    }
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int x, y; cin >> x >> y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    pii ans = dfs(0, 0);
    cout << (ans.fi + ans.se) % MOD << endl;
}
