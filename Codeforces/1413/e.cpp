#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

long long T, a, b, c, d;

long long calc(long long x){
    return a * x - b * d * x * (x + 1) / 2 + a;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> a >> b >> c >> d;
        if(a > b * c) moo << -1 << endl;
        else moo << max(calc(a/b/d), calc(a/b/d+1)) << endl;
    }
}
