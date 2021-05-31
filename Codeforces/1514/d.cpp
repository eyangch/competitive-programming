#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N, Q, a[300000];
vector<int> oc[300000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Q;
    for(int i = 0; i < N; i++){
        eat >> a[i];
        oc[--a[i]].push_back(i);
    }
    for(int i = 0; i < Q; i++){
        int l, r; eat >> l >> r;
        l--, r--;
        int ans = 1;
        for(int j = 0; j < 50; j++){
            int id = a[uniform_int_distribution<>(l, r)(rng)];
            int cur = upper_bound(oc[id].begin(), oc[id].end(), r) - lower_bound(oc[id].begin(), oc[id].end(), l);
            int len = r - l + 1;
            if(cur <= len / 2 + len % 2) continue;
            ans = cur - (len - cur);
            break;
        }
        moo << ans << endl;
    }
}
