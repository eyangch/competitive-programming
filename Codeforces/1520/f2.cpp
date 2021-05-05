#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;
using namespace __gnu_pbds;

int BIT[800000];
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
int T, N, K;

void upd(int i, int x){
    for(; i <= N; i+=i&-i){
        BIT[i] += x;
    }
}

int qry(int i){
    int ret = 0;
    for(; i > 0; i-=i&-i){
        ret += BIT[i];
    }
    return ret;
}

int q(int l, int r){
    moo << "? " << l << " " << r << endl;
    moo.flush();
    int ret; eat >> ret;
    return ret + qry(r) - qry(l-1);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> T;
    map<int, int> m1, m2;
    m1[0] = 1;
    m2[N+1] = N;
    for(int i = 0; i <= N+5; i++){
        oset.insert(i);
    }
    while(T--){
        eat >> K;
        K = *oset.find_by_order(K);
        auto it = m2.upper_bound(K);
        int hi = it->second;
        it = m1.upper_bound(K);
        it--;
        int lo = it->second;
        int mid = 0, ans = hi;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            int qres = q(1, mid);
            int val = mid-qres;
            if(!m2.count(val)) m2[val] = 1e9;
            m2[val] = min(m2[val], mid);
            if(!m1.count(val+1)) m1[val+1] = -1;
            m1[val+1] = max(m1[val+1], mid);
            if(mid - qres >= K){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        moo << "! " << ans << endl;
        moo.flush();
        upd(ans, -1);
        oset.erase(K);
    }
}
