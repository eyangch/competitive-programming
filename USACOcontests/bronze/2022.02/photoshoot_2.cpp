#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int N, a[100000], b[100000], ri[100000], o[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        eat >> b[i];
        ri[b[i]-1] = i;
    }
    int mxri = -1;
    for(int i = 0; i < N; i++){
        if(ri[a[i]-1] > mxri) mxri = ri[a[i]-1];
        else ans++;
    }
    moo << ans << endl;
}
