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
    bool cap = true;
    for(int i = 1; i < (int)s.size(); i++){
        if(s[i] > 'Z') cap = false;
    }
    if(cap){
        for(char &i : s) i += (i > 'Z' ? -32 : 32);
    }
    moo << s << endl;
}
