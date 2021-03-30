#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, r[200001], c[200001], id[200001];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) eat >> r[i];
        for(int i = 0; i < N; i++) eat >> c[i];
        r[N] = c[N] = 1;
        N++;
        iota(id, id+N, 0);
        sort(id, id+N, [](int x, int y){
            return r[x] < r[y];
        });
        int ans = 0;
        for(int i = 1; i < N; i++){
            int cid = id[i], pid = id[i-1];
            if(c[cid] - r[cid] == c[pid] - r[pid]){
                if((c[cid] + r[cid]) % 2 == 0){
                    ans += r[cid] - r[pid];
                }
                continue;
            }
            ans += ((r[cid] - r[pid]) - (c[cid] - c[pid]) + (r[pid] + c[pid]) % 2) / 2;
        }
        moo << ans << endl;
    }
}
