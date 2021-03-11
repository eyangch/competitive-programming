#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    for(int tc = 1; tc <= T; tc++){
        moo << "Case #" << tc << ": ";
        eat >> N >> s;
        for(int i = 0; i < 2*N-2; i++){
            moo << (s[i] == 'E' ? 'S' : 'E');
        }
        moo << endl;
    }
}
