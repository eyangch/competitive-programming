#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, Z, x[200000];

bool works(int mid){
    for(int i = 0; i < mid; i++){
        if(x[N-mid+i] - x[i] < Z) return false;
    }
    return true;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Z;
    for(int i = 0; i < N; i++){
        eat >> x[i];
    }
    sort(x, x+N);
    int lo = 0, hi = N>>1, mid = 0, ans = 0;
    while(lo <= hi){
        mid = (lo+hi)>>1;
        if(works(mid)){
            ans = mid, lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    moo << ans << endl;
}
