#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K;

int qry(int y){
    moo << y << endl;
    moo.flush();
    int ret; eat >> ret;
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        int cur = 0, prev = 0;
        for(int i = 0; i < N; i++){
            cur = prev ^ i;
            if(qry(cur)){
                break;
            }
            prev ^= cur;
        }
    }
}
