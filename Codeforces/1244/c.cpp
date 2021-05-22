#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, P, D, W;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> P >> W >> D;
    set<int> vis;
    for(int i = 0; i * D <= P; i++){
        int cur = P - i * D;
        if(cur % W == 0){
            if(cur/W+i > N) break;
            moo << cur / W << " " << i << " " << N - cur / W - i << endl;
            return 0;
        }
        if(vis.count(cur % W)) break;
        vis.insert(cur % W);
    }
    moo << -1 << endl;
}
