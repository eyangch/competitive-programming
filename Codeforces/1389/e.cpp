#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, M, D, W;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> M >> D >> W;
        int w0 = W / gcd(D-1, W);
        int a = min(M, D) / w0;
        moo << a * min(M, D) - a * (a + 1) * w0 / 2 << endl;
    }
}
