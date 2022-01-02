#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int MOD = 1e9+7;
int T, N, M, R, C, Rd, Cd, P;

int inv(int x){
    int ans = 1;
    for(int i = 0; i < 35; i++){
        if((MOD-2) & (1LL<<i)) ans = ans * x % MOD;
        x = x * x % MOD;
    }
    return ans;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M >> R >> C >> Rd >> Cd >> P;
        R--, C--, Rd--, Cd--;
        int Pb = (100-P) * inv(100) % MOD;
        vector<pair<int, int>> cc;
        int dr = 1, dc = 1, tR = R, tC = C;
        bool ok = 0;
        while(true){
            bool fr = 0, fc = 0;
            if(tR+dr < 0 || tR+dr >= N) dr = -dr, fr = 1;
            if(tC+dc < 0 || tC+dc >= M) dc = -dc, fc = 1;
            if(ok && R == tR && C == tC && (fr || dr == 1) && (fc || dc == 1)) break;
            cc.push_back({tR, tC});
            tR += dr, tC += dc;
            ok = 1;
        };
        reverse(cc.begin(), cc.end());
        int m = 1, b = 0;
        for(pair<int, int> i : cc){
            int r = i.fi, c = i.se;
            b = (b+1)%MOD;
            if(r == Rd || c == Cd){
                m = m * Pb % MOD;
                b = b * Pb % MOD;
            }
        }
        m = (1 - m + MOD) % MOD;
        moo << b * inv(m) % MOD << endl;
    }
}
