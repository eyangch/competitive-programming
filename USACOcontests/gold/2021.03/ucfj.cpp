#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;
using namespace __gnu_pbds;

int N, b[200000], pv[200000];
tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> b[i];
        b[i]--;
    }
    fill(pv, pv+N, -1);
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += oset.order_of_key(pv[b[i]]);
        if(pv[b[i]] != -1){
            oset.erase(oset.find(pv[b[i]]));
        }
        pv[b[i]] = i;
        oset.insert(pv[b[i]]);
    }
    moo << ans << endl;
}
