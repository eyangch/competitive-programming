#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, a, b;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> a >> b;
        int ans = (a + b) / 4;
        ans = min(ans, a);
        ans = min(ans, b);
        moo << ans << endl;
    }
}
