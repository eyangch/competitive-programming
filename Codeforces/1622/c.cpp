#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, K, A[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        for(int i = 0; i < N; i++){
            eat >> A[i];
        }
        sort(A, A+N);
        int tsum = 0;
        for(int i = 0; i < N; i++) tsum += A[i];
        int cnt = 1, tot = A[0];
        int ans = max(0LL, tsum - K);;
        for(int i = N-1; i > 0; i--){
            cnt++, tot += A[i];
            int v1 = K + tot - tsum;
            int v2 = (v1 / cnt);
            if(v1 < 0 && v1 % cnt) v2--;
            int v3 = max(0LL, A[0] - v2);
            int v4 = v3 + cnt - 1;
            ans = min(ans, v4);
        }
        moo << max(0LL, ans) << endl;
    }
}
