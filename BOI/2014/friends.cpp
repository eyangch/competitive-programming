#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int N, M;
string U, S = "-";

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> U;
    if(N % 2 == 0){
        moo << "NOT POSSIBLE" << endl;
        return 0;
    }
    M = N/2;
    string sc = U.substr(0, M);
    int id = 0;
    for(int i = M; i < N; i++){
        if(id >= M) break;
        if(sc[id] == U[i]){
            id++;
        }
    }
    if(id == M) S = sc;
    sc = U.substr(M+1, M);
    id = 0;
    for(int i = 0; i < M+1; i++){
        if(id >= M) break;
        if(sc[id] == U[i]) id++;
    }
    if(id == M){
        if(S != "-" && S != sc){
            moo << "NOT UNIQUE" << endl;
            return 0;
        }
        S = sc;
    }
    if(S == "-") moo << "NOT POSSIBLE" << endl;
    else moo << S << endl;
}
