#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, Q, ans;
set<int> s[200000];
bool bad[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    ans = N;
    for(int i = 0; i < M; i++){
        int u, v; eat >> u >> v;
        s[u-1].insert(v-1);
        s[v-1].insert(u-1);
        if(!bad[u-1] && *s[u-1].rbegin() > u-1) ans--, bad[u-1] = 1;
        if(!bad[v-1] && *s[v-1].rbegin() > v-1) ans--, bad[v-1] = 1;
    }
    eat >> Q;
    while(Q--){
        int op; eat >> op;
        if(op == 1){
            int u, v; eat >> u >> v;
            s[u-1].insert(v-1);
            s[v-1].insert(u-1);
            if(!bad[u-1] && *s[u-1].rbegin() > u-1) ans--, bad[u-1] = 1;
            if(!bad[v-1] && *s[v-1].rbegin() > v-1) ans--, bad[v-1] = 1;
        }else if(op == 2){
            int u, v; eat >> u >> v;
            s[u-1].erase(v-1);
            s[v-1].erase(u-1);
            if(bad[u-1] && ((int)s[u-1].size() == 0 || *s[u-1].rbegin() < u-1)) ans++, bad[u-1] = 0;
            if(bad[v-1] && ((int)s[v-1].size() == 0 || *s[v-1].rbegin() < v-1)) ans++, bad[v-1] = 0;
        }else{
            moo << ans << endl;
        }
    }
}
