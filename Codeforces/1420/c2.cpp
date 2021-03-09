#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, Q, a[300002];

int hill(int id){
    if(id == 0 || id == N+1) return 0;
    if(a[id] > a[id-1] && a[id] > a[id+1]) return a[id];
    if(a[id] < a[id-1] && a[id] < a[id+1]) return -a[id];
    return 0;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> Q;
        for(int i = 1; i <= N; i++){
            eat >> a[i];
        }
        a[0] = a[N+1] = 0;
        int ans = 0;
        for(int i = 1; i <= N; i++){
            ans += hill(i);
        }
        moo << ans << endl;
        for(int i = 0; i < Q; i++){
            int l, r; eat >> l >> r;
            if(l != r){
                ans -= hill(l) + hill(l-1) + hill(l+1);
                if(r > l + 2) ans -= hill(r-1);
                if(r > l + 1) ans -= hill(r);
                ans -= hill(r+1);
                swap(a[l], a[r]);
                ans += hill(l) + hill(l-1) + hill(l+1);
                if(r > l + 2) ans += hill(r-1);
                if(r > l + 1) ans += hill(r);
                ans += hill(r+1);
            }
            moo << ans << endl;
        }
    }
}
