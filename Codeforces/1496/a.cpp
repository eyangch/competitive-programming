#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, K;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K >> s;
        bool ok = true;
        for(int i = 0; i < K; i++){
            if(s[i] != s[N-i-1]) ok = false;
        }
        if(K * 2 >= N) ok = false;
        moo << (ok ? "yEs" : "nO") << endl;
    }
}
