#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;
typedef long long ll;

int N, M, a[500000], b[500000];
ll K;
int compact[1000000], lid[1000000];
bool vis[500000];
int lane_n[500000], lane_n2[500000];
int lane_sz;

ll angry(ll x){
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ll av = x / N + (i < x % N);
        int id = lane_n[i];
        if(id != lid[a[i]]) continue;
        int gap = (compact[a[i]] + lane_sz - lane_n2[i]) % lane_sz;
        ans += av / lane_sz + (gap < av % lane_sz);
    }
    return x - ans;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M >> K;
    for(int i = 0; i < N; i++){
        eat >> a[i];
        a[i]--;
    }
    for(int i = 0; i < M; i++){
        eat >> b[i];
        b[i]--;
    }
    if(N > M){
        swap(N, M);
        swap(a, b);
    }
    int lane_id = 0;
    for(int i = 0; i < M; i++){
        if(vis[i]) continue;
        int ptr = i;
        int lane_cnt = 0;
        while(!vis[ptr]){
            vis[ptr] = true;
            lane_n[ptr] = lane_id;
            lane_n2[ptr] = lane_cnt;
            compact[b[ptr]] = lane_cnt++;
            lid[b[ptr]] = lane_id;
            ptr = (ptr + N) % M;
        }
        lane_sz = lane_cnt;
        lane_id++;
    }
    ll lo = 0, hi = 1e18, mid = 0, ans = 0;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(angry(mid) < K) lo = mid+1;
        else hi = mid-1, ans = mid;
    }
    moo << ans << endl;
}
