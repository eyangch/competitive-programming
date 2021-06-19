#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K, e;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K >> s;
    int mb = 0;
    for(e = 1; e < N; e++){
        if(s[e] > s[mb]) break;
        if(s[e] == s[mb]) mb++;
        else mb = 0;
    }
    for(int i = 0; i < K; i++) moo << s[i % (e-mb)];
    moo << endl;
}
