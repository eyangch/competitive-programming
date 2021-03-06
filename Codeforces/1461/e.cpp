#include <bits/stdc++.h>
#define endl "\n"
#define moo cout
#define int long long

using namespace std;

int k, l, r, t, x, y;
bool dp[1000000];

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> k >> l >> r >> t >> x >> y;
    if(x == y){
        if(k + y <= r) k += y;
        moo << (k - x >= l ? "Yes" : "No") << endl;
    }else if(x > y){
        if(k+y > r) k -= y;
        int diff = k - l;
        if(diff / (x - y) >= t){
            moo << "Yes" << endl;
        }else{
            moo << "No" << endl;
        }
    }else{
        int targ = r - y;
        bool ok = true;
        if(k <= targ) k += y;
        while(t > 0){
            k -= x;
            t--;
            if(t == 0 || dp[k % x]){
                break;
            }
            int n = min(t, max(0LL, (k - targ + x - 1) / x));
            k -= n * x;
            t -= n;
            if(k < l){
                ok = false;
                break;
            }
            dp[k % x] = true;
            k += y;
        }
        moo << (ok ? "Yes" : "No") << endl;
    }
}
