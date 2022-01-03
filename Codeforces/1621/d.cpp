#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, c[500][500];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < 2*N; i++){
            for(int j = 0; j < 2*N; j++){
                eat >> c[i][j];
            }
        }
        int ans = 0;
        for(int i = N; i < 2 * N; i++){
            for(int j = N; j < 2 * N; j++){
                ans += c[i][j];
            }
        }
        ans += min({c[0][N], c[N][0], c[N-1][N], c[N][N-1], c[N-1][2*N-1], c[2*N-1][N-1], c[0][2*N-1], c[2*N-1][0]});
        moo << ans << endl;
    }
}
