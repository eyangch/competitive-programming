#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, occ[26];
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        fill(occ, occ+26, 0);
        eat >> s;
        for(char i : s){
            occ[i-'a']++;
        }
        int tot = 0;
        for(int i = 0; i < 26; i++){
            tot += min(2LL, occ[i]);
        }
        moo << tot/2 << endl;
    }
}
