#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;
typedef long long ll;

int N, K, psame[200000], ssame[200000];
ll a[200000], pfx[200000], sfx[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    sort(a, a+N);
    pfx[0] = a[0];
    for(int i = 1; i < N; i++){
        pfx[i] = pfx[i-1] + a[i];
    }
    sfx[N-1] = a[N-1];
    for(int i = N-2; i >= 0; i--){
        sfx[i] = sfx[i+1] + a[i];
    }
    fill_n(psame, N, 1);
    fill_n(ssame, N, 1);
    for(int i = 1; i < N; i++){
        if(a[i] == a[i-1]) psame[i] = psame[i-1]+1;
    }
    for(int i = N-2; i >= 0; i--){
        if(a[i] == a[i+1]) ssame[i] = ssame[i+1]+1;
    }
    ll ans = 1e17;
    for(int i = 0; i < N; i++){
        ll p = a[i] * (i+1) - pfx[i], s = sfx[i] - a[i] * (N-i);
        if(i+1 >= K) ans = min(ans, p - (i+1-max(K, psame[i])));
        if(N-i >= K) ans = min(ans, s - (N-i-max(K, ssame[i])));
        ans = min(ans, p+s - (N-max(K, psame[i] + ssame[i] - 1)));
        if(psame[i] >= K) ans = 0;
    }
    moo << ans << endl;
}
