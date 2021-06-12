#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, L, R, a[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> L >> R;
        for(int i = 0; i < N; i++) eat >> a[i];
        sort(a, a+N);
        int ptrl = N-1, ptrr = N-1;
        int ans = 0;
        for(int i = 0; i < N; i++){
            while(ptrl >= 0 && a[i] + a[ptrl] >= L) ptrl--;
            while(ptrr >= 0 && a[i] + a[ptrr] > R) ptrr--;
            ans += ptrr - ptrl - (i > ptrl && i <= ptrr);
        }
        moo << ans/2 << endl;
    }
}
