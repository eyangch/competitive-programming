#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N;
string s;

int dx[128], dy[128], side[128];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> s;
    int ans = 0;
    dx['L'] = dy['D'] = -1;
    dx['R'] = dy['U'] = 1;
    side['L'] = side['U'] = 1;
    int x = 0, y = 0;
    for(int i = 0; i < N-1; i++){
        x += dx[s[i]], y += dy[s[i]];
        if(x == y && side[s[i]] == side[s[i+1]]) ans++;
    }
    moo << ans << endl;
}
