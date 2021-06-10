#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int R, G, B;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> R >> G >> B;
    if(R < G) swap(R, G);
    if(B > R) swap(B, R);
    if(B > G) swap(B, G);
    int ans = B;
    if(R - 2 * B < 2 * G){
        ans += (R - B + G - B) / 3;
    }else{
        ans += G;
    }
    moo << ans << endl;
}
