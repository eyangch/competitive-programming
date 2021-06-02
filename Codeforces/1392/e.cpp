#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, Q;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            moo << (i % 2 ? (1LL << (i+j-1)) : 0) << " ";
        }
        moo << endl;
    }
    moo.flush();
    eat >> Q;
    while(Q--){
        int k; eat >> k;
        int x = 0, y = 0;
        for(int i = 0; i < 2*N-1; i++){
            moo << x+1 << " " << y+1 << endl;
            if((k&1) == x%2) y++;
            else x++;
            k >>= 1;
        }
        moo.flush();
    }
}
