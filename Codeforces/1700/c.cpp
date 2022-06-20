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
        for(int i = 0; i < N; i++) eat >> a[i];
        int ops = 0, mn = 0;
        for(int i = 1; i < N; i++){
            a[i] -= mn;
            int df = abs(a[i-1] - a[i]);
            ops += df;
            if(a[i-1] < a[i]){
                mn += df;
                a[i] = a[i-1];
            }
        }
        moo << ops + abs(a[N-1]) << endl;
    }
}
