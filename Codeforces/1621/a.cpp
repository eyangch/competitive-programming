#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, K;
char C[40][40];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        for(int i = 0; i < N; i++) fill(C[i], C[i]+N, '.');
        int ci = 0;
        for(int i = 0; i < K; i += 1){
            if(ci >= N){
                ci = -1;
                break;
            }
            C[ci][ci] = 'R';
            ci += 2;
        }
        if(ci == -1) moo << -1 << endl;
        else{
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) moo << C[i][j];
                moo << endl;
            }
        }
    }
}
