#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string s;
int occ[26];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> s;
    for(int i = 0; i < (int)s.size(); i++){
        occ[s[i]-'a']++;
    }
    int g = 0;
    for(int i = 0; i < 26; i++){
        if(occ[i] == 0) continue;
        if(g == 0) g = occ[i];
        else{
            g = gcd(occ[i], g);
        }
    }
    if(g == 1){
        moo << "IMPOSSIBLE" << endl;
    }else{
        string rep = "";
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < occ[i] / g; j++){
                rep += (char)(i+'a');
            }
        }
        for(int i = 0; i < g; i++) moo << rep;
        moo << endl;
    }
}
