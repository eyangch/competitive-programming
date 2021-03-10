#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K, c[500000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K;
    for(int i = 0; i < N; i++){
        eat >> c[i];
    }
    sort(c, c+N);
    int val = 0, b = 0;
    for(int i = N-1; i >= 0; i--){
        val += b;
        b += c[i];
    }
    if(K == 0){
        moo << val << endl;
        return 0;
    }
    int ans = val, cur = 0;
    for(int i = 0; i < N; i++){
        cur += (i/(K+1)) * c[i];
        int mxh = (i/(K+1)+1);
        val -= (b -= c[i]);
        ans = max(ans, cur + val + b * mxh);
    }
    moo << ans << endl;
}
