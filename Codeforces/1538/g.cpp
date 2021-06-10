#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, x, y, a, b;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> x >> y >> a >> b;
        if(a == b){
            moo << min(x, y) / a << endl;
            continue;
        }
        if(x > y) swap(x, y);
        if(a > b) swap(a, b);
        int ans = 0;
        if(y - x > b - a){
            int numgap = (y-x)/(b-a);
            int smmx = x/a;
            int sub = min(smmx, numgap);
            ans = sub;
            x -= a * sub;
            y -= b * sub;
        }
        int ans1 = 2 * (x / (a+b)) + (x % (a+b) >= a);
        int ans2 = 2 * (y / (a+b)) + (y % (a+b) >= b);
        moo << ans + min(ans1, ans2) << endl;
    }
}
