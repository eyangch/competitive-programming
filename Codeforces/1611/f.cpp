#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, S, A[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> S;
        for(int i = 0; i < N; i++) eat >> A[i];
        int best = -1;
        int bl = 0;
        int br = 0;
        int ptr = 0;
        for(int i = 0; i < N; i++){
            while(ptr < N && S + A[ptr] >= 0){
                S += A[ptr++];
            }
            if(ptr - i > best && ptr > i){
                best = ptr - i;
                br = ptr;
                bl = i+1;
            }
            S -= A[i];
        }
        if(~best){
            moo << bl << ' ' << br << endl;
        }else{
            moo << -1 << endl;
        }
    }
}
