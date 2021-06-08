#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int T, N, M, p2[5000000];
string s[2000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    p2[0] = 1;
    for(int i = 1; i < 5000000; i++){
        p2[i] = p2[i-1] * 2 % MOD;
    }
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++) eat >> s[i];
        int nz = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(s[i][j] == '#') nz++;
            }
        }
        moo << (nz == N*M ? p2[nz] - 1 : p2[nz]) << endl;
    }
}
