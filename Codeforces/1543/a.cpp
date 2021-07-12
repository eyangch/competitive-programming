#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, a, b;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> a >> b;
        if(a == b) moo << "0 0" << endl;
        else{
            if(a < b) swap(a, b);
            int diff = a - b;
            moo << diff << ' ' << min(a%diff, diff-a%diff) << endl;
        }
    }
}
