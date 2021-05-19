#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define f first
#define s second

using namespace std;
typedef pair<int, int> pii;

int N, M, a[300000][8];

pair<int, int> works(int x){
    int v[1<<M];
    fill(v, v+(1<<M), -1);
    for(int i = 0; i < N; i++){
        int cur = 0;
        for(int j = 0; j < M; j++){
            if(a[i][j] >= x){
                cur |= 1<<j;
            }
        }
        v[cur] = i;
    }
    for(int i = 0; i < 1<<M; i++){
        if(v[i] == -1) continue;
        for(int j = i; j < 1<<M; j++){
            if(v[j] == -1) continue;
            if((i | j) == (1<<M) - 1){
                return {v[i], v[j]};
            }
        }
    }
    return {-1, -1};
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            eat >> a[i][j];
        }
    }
    int lo = 0, hi = 1e9, ans = 0, mid = 0;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(works(mid).f == -1){
            hi = mid-1;
        }else{
            ans = mid;
            lo = mid+1;
        }
    }
    pii x = works(ans);
    moo << x.f+1 << " " << x.s+1 << endl;
}
