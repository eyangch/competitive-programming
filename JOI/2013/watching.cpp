#include <bits/stdc++.h>

using namespace std;

int N, P, Q;
int a[100000];
int dp[2001][2001]; // [num of events][large cameras]
int jmps[2001], jmpl[2001];

bool works(int mid){
    fill(dp[0], dp[N]+Q+1, 1e9);
    fill(dp[0], dp[0]+Q+1, 0);
    iota(jmps, jmps+N+1, -1);
    iota(jmpl, jmpl+N+1, -1);
    for(int i = N-1; i >= 0; i--){
        int idxs = upper_bound(a, a+N, a[i]-mid) - a - 1;
        int idxl = upper_bound(a, a+N, a[i]-2*mid) - a - 1;
        jmps[i] = idxs;
        jmpl[i] = idxl;
    }
    for(int i = 1; i <= N; i++){
        int pvs = jmps[i-1]+1, pvl = jmpl[i-1]+1;
        dp[i][0] = dp[pvs][0] + 1;
        for(int j = 1; j <= Q; j++){
            dp[i][j] = min(dp[pvl][j-1], dp[pvs][j] + 1);
        }
    }
    return (dp[N][Q] <= P);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> P >> Q;
    if(P+Q >= N){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a+N);
    int lo = 0, hi = 1e9, mid = 0;
    while(lo < hi){
        mid = (lo + hi) / 2;
        if(works(mid)){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    while(works(mid)) mid--;
    while(!works(mid)) mid++;
    cout << mid << endl;
}
