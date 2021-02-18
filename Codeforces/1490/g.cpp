#include <bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int T, N, M, total;
map<int, int> mx;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        mx.clear();
        total = 0;
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            int x; cin >> x;
            total += x;
            auto lb = mx.lower_bound(total);
            if(lb != mx.end() && lb->second <= i) continue;
            vector<int> rm;
            auto it = mx.upper_bound(total);
            if(it != mx.begin()){
                it--;
                for(; true; it--){
                    if(it->second < i) break;
                    rm.push_back(it->first);
                    if(it == mx.begin()) break;
                }
                for(int i : rm){
                    mx.erase(i);
                }
            }
            mx[total] = i;
        }
        for(int i = 0; i < M; i++){
            int x; cin >> x;
            int y = max(0LL, x - mx.rbegin()->first);
            if((int)mx.size() == 0 || (y > 0 && total <= 0)){
                cout << -1 << " ";
                continue;
            }
            int z = 0, w = x;
            if(y > 0){
                z = (y + total - 1) / total;
                w -= total * z;
                assert(w <= mx.rbegin()->first);
            }
            int idx = mx.lower_bound(w)->second;
            z *= N;
            cout << z + idx << " ";
        }
        cout << endl;
    }
}
