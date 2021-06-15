#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[50];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) eat >> a[i];
        bool sorted = true;
        for(int i = 1; i < N; i++){
            if(a[i] != a[i-1] + 1) sorted = false;
        }
        if(sorted){
            moo << 0 << endl;
            continue;
        }
        if(a[0] == 1 || a[N-1] == N){
            moo << 1 << endl;
            continue;
        }
        if(a[0] == N && a[N-1] == 1){
            moo << 3 << endl;
            continue;
        }
        moo << 2 << endl;
    }
}
