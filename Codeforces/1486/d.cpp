#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, K, a[200000], dp[200000];

int sf(int id, int mid){
    return 1 - 2 * (a[id] < mid);
}

bool ok(int mid){
    for(int i = 0; i < N; i++){
        dp[i] = 0;
    }
    int sum = 0;
    for(int i = 0; i < K; i++){
        sum += sf(i, mid);
    }
    dp[K-1] = sum;
    if(dp[K-1] > 0) return true;
    for(int i = K; i < N; i++){
        sum += sf(i, mid) - sf(i-K, mid);
        dp[i] = max(dp[i-1] + sf(i, mid), sum);
        if(dp[i] > 0) return true;
    }
    return false;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int lo = 1, hi = N, mid = 0, ans = 0;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(ok(mid)) lo = mid+1, ans = mid;
        else hi = mid-1;
    }
    cout << ans << endl;
}
