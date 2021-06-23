#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, s[4];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        int x; eat >> x;
        s[x-1]++;
    }
    int ans = s[3];
    ans += s[2];
    s[0] -= s[2];
    ans += s[1]/2 + s[1]%2;
    if(s[1] % 2) s[0] -= 2;
    ans += max(0LL, s[0] / 4 + (s[0] % 4 > 0));
    moo << ans << endl;
}
