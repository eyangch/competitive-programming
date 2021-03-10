#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, K, a[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        sort(a, a+N);
        int mex = 0;
        for(int i = 0; i < N; i++){
            if(a[i] == mex) mex++;
        }
        if(mex > a[N-1]){
            moo << N + K << endl;
        }else if(K > 0){
            int ans = N;
            int nxt = (mex + a[N-1] + 1) / 2;
            if(!binary_search(a, a+N, nxt)) ans++;
            moo << ans << endl;
        }else{
            moo << N << endl;
        }
    }
}
