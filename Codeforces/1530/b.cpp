#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, H, W;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> H >> W;
        string tb = "";
        for(int i = 0; i < W; i++){
            tb += ('1' - i%2);
        }
        moo << tb << endl;
        for(int i = 1; i < H - 1; i++){
            string cur = string(W, '0');
            if(i % 2 == 0 && i != H-2){
                cur[0] = cur[W-1] = '1';
            }
            moo << cur << endl;
        }
        moo << tb << endl;
    }
}
