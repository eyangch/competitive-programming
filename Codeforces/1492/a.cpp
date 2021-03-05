#include <bits/stdc++.h>
#define endl "\n"
#define moo cout

using namespace std;

int T;
long long p, a, b, c;

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> p >> a >> b >> c;
        moo << min({(p+a-1)/a*a - p, (p+b-1)/b*b - p, (p+c-1)/c*c - p}) << endl;
    }
}
