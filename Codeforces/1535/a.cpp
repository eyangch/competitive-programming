#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        int a, b, c, d; eat >> a >> b >> c >> d;
        if(a < b) swap(a, b);
        if(c < d) swap(c, d);
        if(a > d && c > b) moo << "YES" << endl;
        else moo << "NO" << endl;
    }
}
