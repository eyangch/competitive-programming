#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int Q;
int a[300005], c[300005], p[300005];
int up[22][300005];
bool del[300005];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    int a0, c0;
    eat >> Q >> a[0] >> c[0];
    p[0] = 0;
    for(int i = 0; i < 22; i++) up[i][0] = 0;
    for(int i = 1; i <= Q; i++){
        int t; eat >> t;
        if(t == 1){
            int pi, ai, ci; eat >> pi >> ai >> ci;
            p[i] = pi;
            a[i] = ai;
            c[i] = ci;
            up[0][i] = p[i];
            for(int j = 1; j < 22; j++){
                up[j][i] = up[j-1][up[j-1][i]];
            }
        }else{
            int v, w; eat >> v >> w;
            int og_w = w;
            int og_v = v;
            int ans = 0;
            while(w && a[v]){
                for(int j = 21; j >= 0; j--){
                    if(a[up[j][v]]) v = up[j][v];
                }
                if(a[v] > w){
                    a[v] -= w;
                    ans += w * c[v];
                    w = 0;
                }else{
                    ans += a[v] * c[v];
                    w -= a[v];
                    a[v] = 0;
                }
                v = og_v;
            }
            moo << og_w - w << " " << ans << endl;
        }
        moo.flush();
    }
}
