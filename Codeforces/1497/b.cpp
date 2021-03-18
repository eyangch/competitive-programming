#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, M;
multiset<int> a;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++){
            int x; eat >> x;
            a.insert(x%M);
        }
        int ans = 0;
        if(a.find(0) != a.end()) ans++;
        a.erase(0);
        for(int i = 1; i < M; i++){
            int oc1 = a.count(i);
            int oc2 = a.count(M-i);
            if(oc1 != oc2){
                ans += abs(oc1 - oc2) - 1;
            }
            if(oc1 || oc2) ans++;
            a.erase(i), a.erase(M-i);
        }
        moo << ans << endl;
    }
}
