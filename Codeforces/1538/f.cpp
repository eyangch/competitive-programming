#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, l, r;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> l >> r;
        int ans = 0;
        while(l > 0 || r > 0){
            ans += r - l;
            l /= 10, r /= 10;
        }
        moo << ans << endl;
    }
}
