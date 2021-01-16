#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

struct r{
    int x;
    int y;
    int i;
};

int N;
r a[200000];
int ans[200000];
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pv;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i].x >> a[i].y;
        a[i].i = i;
    }
    sort(a, a+N, [](r a, r b){
        if(a.y == b.y) return a.x > b.x;
        return a.y < b.y;
    });
    for(int i = 0; i < N; i++){
        ans[a[i].i] = i - pv.order_of_key({a[i].x, -1});
        pv.insert({a[i].x, i});
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    sort(a, a+N, [](r a, r b){
        if(a.x == b.x) return a.y > b.y;
        return a.x < b.x;
    });
    pv.clear();
    for(int i = 0; i < N; i++){
        ans[a[i].i] = i - pv.order_of_key({a[i].y, -1});
        pv.insert({a[i].y, i});
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
