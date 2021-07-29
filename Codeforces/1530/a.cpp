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
        int x = 0;
        for(char i : s) x = max(x, (int)(i - '0'));
        moo << x << endl;
    }
}
