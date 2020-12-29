#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

int N, K;
int x[200000];
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

signed main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    for(int i = 0; i < K; i++){
        oset.insert({x[i], i});
    }
    cout << (*oset.find_by_order((K-1)/2)).first << " ";
    for(int i = K; i < N; i++){
        oset.insert({x[i], i});
        oset.erase(oset.find({x[i-K], i-K}));
        cout << (*oset.find_by_order((K-1)/2)).first << " ";
    }
    cout << endl;
}
