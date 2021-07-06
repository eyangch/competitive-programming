#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, e[50000], pfx[50000], sfx[50000];

int32_t main(){
    freopen("cardgame.in", "r", stdin); freopen("cardgame.out", "w", stdout);
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++) {
        eat >> e[i];
        e[i]--;
    }
    set<int> es(e, e+N);
    set<int> bs;
    for(int i = 0; i < 2*N; i++){
        if(!es.count(i)) bs.insert(i);
    }
    set<int> btmp(bs);
    for(int i = 0; i < N; i++){
        auto it = btmp.upper_bound(e[i]);
        if(i > 0) pfx[i] = pfx[i-1];
        if(it != btmp.end()){
            pfx[i]++;
            btmp.erase(it);
        }
    }
    btmp = set<int>(bs);
    for(int i = N-1; i >= 0; i--){
        auto it = btmp.upper_bound(e[i]);
        if(i < N-1) sfx[i] = sfx[i+1];
        if(it != btmp.begin()){
            it--;
            sfx[i]++;
            btmp.erase(it);
        }
    }
    int ans = max(pfx[N-1], sfx[0]);
    for(int i = 0; i < N-1; i++){
        ans = max(ans, pfx[i] + sfx[i+1]);
    }
    moo << ans << endl;
}
