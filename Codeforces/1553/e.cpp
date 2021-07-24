#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, p[300000], occ[300000], vis[300000], nxt[300000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        fill(occ, occ+N, 0);
        for(int i = 0; i < N; i++){
            int x; eat >> x;
            occ[((i - (x - 1)) % N + N) % N]++;
            p[i] = x-1;
        }
        vector<int> ans;
        for(int i = 0; i < N; i++){
            if(occ[i] >= N - 2*M){
                for(int j = 0; j < N; j++){
                    nxt[(j-i+N)%N] = p[j];
                }
                fill(vis, vis+N, 0);
                int ops = 0;
                for(int j = 0; j < N; j++){
                    if(vis[j]) continue;
                    int cur = j, sz = 0;
                    while(!vis[cur]){
                        vis[cur] = true;
                        sz++, cur = nxt[cur];
                    }
                    ops += sz - 1;
                }
                if(ops <= M) ans.push_back(i);
            }
        }
        moo << ans.size();
        for(int i : ans) moo << ' ' << i;
        moo << endl;
    }
}
