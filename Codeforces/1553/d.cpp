#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T;
string s, t;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> s >> t;
        int ti = t.size()-1, si = s.size()-1;
        while(ti >= 0 && si >= 0){
            if(s[si] != t[ti]) si -= 2;
            else si--, ti--;
        }
        if(ti == -1) moo << "YES" << endl;
        else moo << "NO" << endl;
    }
}
