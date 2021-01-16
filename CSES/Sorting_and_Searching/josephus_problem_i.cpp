#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int N;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        oset.insert(i);
    }
    int idx = 1;
    while(N > 0){
        auto it = oset.find_by_order(idx);
        cout << *it + 1 << " ";
        oset.erase(it);
        N--;
        if(N) idx = (idx + 1) % N;
    }
    cout << endl;
}
