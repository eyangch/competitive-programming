#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, a[200000], p1[200000], p2[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    p1[0] = a[0];
    for(int i = 1; i < N; i++){
        p1[i] = p1[i-1] + !(i%2) * a[i];
        p2[i] = p2[i-1] + (i%2) * a[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max({ans, p1[i] + p2[N-1] - p2[i], p2[i] + p1[N-1] - p1[i]});
    }
    moo << ans << endl;
}
