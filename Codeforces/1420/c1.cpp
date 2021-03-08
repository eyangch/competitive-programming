#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, Q, a[300000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> Q;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        int max1 = 0, max2 = 0;
        for(int i = 0; i < N; i++){
            int tmp1 = max2 + a[i];
            int tmp2 = max1 - a[i];
            max1 = max(max1, tmp1);
            max2 = max(max2, tmp2);
        }
        cout << max1 << endl;
    }
}
