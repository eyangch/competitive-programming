#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, M, X[10], W[10000], P[10000], bP[10000], ans[10000];
string S[10];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++) eat >> X[i];
        for(int i = 0; i < N; i++) eat >> S[i];
        iota(P, P+M, 0);
        int mv = -1;
        for(int i = 0; i < 1<<N; i++){
            fill(W, W+M, 0);
            for(int j = 0; j < M; j++){
                for(int k = 0; k < N; k++){
                    W[j] -= (S[k][j] - '0') * ((i >> k & 1) * 2 - 1);
                }
            }
            sort(P, P+M, [](int a, int b){return W[a] < W[b];});
            int cv = 0;
            for(int j = 0; j < N; j++) cv += X[j] * ((i >> j & 1) * 2 - 1);
            for(int j = 0; j < M; j++) cv += (j+1) * W[P[j]];
            if(cv > mv){
                mv = cv;
                copy(P, P+M, bP);
            }
        }
        for(int i = 0; i < M; i++) ans[bP[i]] = i+1;
        for(int i = 0; i < M; i++) moo << ans[i] << ' ';
        moo << endl;
    }
}
