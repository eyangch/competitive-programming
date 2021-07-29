#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[100000], b[100000];

bool works(int x){
    int tot = N + x, dis = tot / 4;
    int a1 = 100 * x + accumulate(a, a+N, 0);
    int b1 = accumulate(b, b+N, 0);
    if(dis >= N){
        a1 = 100 * (tot - dis);
    }else{
        a1 -= accumulate(a, a+dis, 0);
    }
    if(dis >= x){
        b1 -= accumulate(b, b+dis-x, 0);
    }
    return (a1 >= b1);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) eat >> a[i];
        for(int i = 0; i < N; i++) eat >> b[i];
        sort(a, a+N);
        sort(b, b+N);
        int lo = 0, hi = 1e7, mid = 0, ans = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(works(mid)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        moo << ans << endl;
    }
}
