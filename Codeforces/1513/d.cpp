#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, P, a[200000], ids[200000];
bool e[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> P;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        iota(ids, ids+N, 0);
        sort(ids, ids+N, [](int x, int y){
            return a[x] < a[y];
        });
        fill(e, e+N, false);
        int rem = N-1, ans = 0;
        for(int i = 0; i < N; i++){
            int id = ids[i];
            if(a[id] >= P) break;
            for(int j = id+1; j < N && a[j] % a[id] == 0 && !e[j-1]; j++){
                e[j-1] = true;
                rem--;
                ans += a[id];
            }
            for(int j = id-1; j >= 0 && a[j] % a[id] == 0 && !e[j]; j--){
                e[j] = true;
                rem--;
                ans += a[id];
            }
        }
        ans += rem * P;
        moo << ans << endl;
    }
}
