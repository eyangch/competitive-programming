#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout

using namespace std;

int T, N;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> s;
        int z = 0;
        for(char i : s) z += (i == '0');
        if(z % 2 && z != 1) moo << "ALICE" << endl;
        else moo << "BOB" << endl;
    }
}
