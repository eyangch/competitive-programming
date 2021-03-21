#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, K;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        N += 3 - K;
        if(N % 2) moo << 1 << " " << N/2 << " " << N/2;
        else if(N % 4) moo << 2 << " " << N/2-1 << " " << N/2-1;
        else moo << N/2 << " " << N/4 << " " << N/4;
        for(int i = 0; i < K - 3; i++){
            moo << " " << 1;
        }
        moo << endl;
    }
}
