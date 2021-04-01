#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    string a; eat >> a;
    int ans = 0;
    while(true){
        ans = 0;
        for(char i : a) ans += i-'0';
        a = to_string(ans);
        if(a.size() == 1) break;
    }
    moo << ans << endl;
}
