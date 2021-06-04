#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> s;
        int ans = 0;
        int dp0 = 0, dp1 = 0; // make cur = 0, make cur = 1
        for(int i = 0; i < (int)s.length(); i++){
            if(s[i] == '0') dp1 = i+1;
            if(s[i] == '1') dp0 = i+1;
            ans += i - min(dp0, dp1) + 1;
            swap(dp0, dp1);
        }
        moo << ans << endl;
    }
}
