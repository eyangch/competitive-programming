#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, a[200000], occ[200000], c[200000], cfi[200000], ans[200000], id[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        fill(occ, occ+N, 0);
        fill(ans, ans+N, 0);
        iota(id, id+N, 0);
        for(int i = 0; i < N; i++){
            eat >> a[i];
            a[i]--;
            occ[a[i]]++;
        }
        sort(id, id+N, [](int x, int y){
            return a[x] < a[y];
        });
        int tot = 0;
        for(int i = 0; i < N; i++){
            occ[i] = min(K, occ[i]);
            tot += occ[i];
        }
        tot = tot/K * K;
        int cur = 0;
        for(int i = 0; i < N; i++){
            if(tot == 0) break;
            if(occ[a[id[i]]] == 0) continue;
            ans[id[i]] = cur + 1;
            cur = (cur + 1) % K;
            occ[a[id[i]]]--;
            tot--;
        }
        for(int i = 0; i < N; i++){
            moo << ans[i] << ' ';
        }
        moo << endl;
    }
}
