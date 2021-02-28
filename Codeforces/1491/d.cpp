#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int Q;

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        bitset<30> a(u), b(v);
        int cnt = 0;
        bool good = true;
        for(int i = 0; i < 30; i++){
            cnt += a[i] - b[i];
            if(cnt < 0){
                good = false;
                break;
            }
        }
        cout << (good && u <= v ? "yEs" : "nO") << endl;
    }
}
