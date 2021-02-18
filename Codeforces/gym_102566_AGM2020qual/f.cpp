#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define int long long

using namespace std;
using namespace __gnu_pbds;

int T, N, a[100000];

tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        oset.clear();
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = N-1; i >= 0; i--){
            ans += 8 * oset.order_of_key({a[i], -1});
            oset.insert({a[i], i});
        }
        cout << ans << endl;
    }
}
