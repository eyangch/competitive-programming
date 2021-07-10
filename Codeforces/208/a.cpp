#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> s;
    string ans = "";
    for(int i = 0; i < (int)s.size(); i++){
        if(s.substr(i, 3) == "WUB"){
            i += 2;
            if(ans.size() && ans[ans.size()-1] != ' ') ans += ' ';
        }
        else ans += s[i];
    }
    moo << ans << endl;
}
