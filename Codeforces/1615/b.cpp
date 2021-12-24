#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int pfx[200001][20];
int T, l, r;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    for(int i = 0; i < 20; i++){
        pfx[0][i] = 0;
        for(int j = 1; j <= 200000; j++){
            pfx[j][i] = pfx[j-1][i] + ((j & (1<<i)) > 0);
        }
    }
    eat >> T;
    while(T--){
        eat >> l >> r;
        int ans = 1e15;
        for(int i = 0; i < 20; i++){
            int amt = (r - l + 1) - (pfx[r][i] - pfx[l-1][i]);
            ans = min(ans, amt);
        }
        moo << ans << endl;
    }
}
