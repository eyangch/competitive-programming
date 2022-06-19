#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        if(a[0] == N){
            moo << N;
            for(int i = N-1; i > 0; i--){
                moo << ' ' << a[i];
            }
        }else if(a[N-1] == N){
            for(int i = N-2; i >= 0; i--){
                moo << a[i] << ' ';
            }
            moo << N;
        }else{
            moo << -1;
        }
        moo << endl;
    }
}
