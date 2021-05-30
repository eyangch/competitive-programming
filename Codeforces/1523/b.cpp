#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, a[1000];
vector<int> op;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        op.clear();
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        moo << 3 * N << endl;
        for(int i = 0; i < N; i += 2){
            moo << "1 " << i+1 << " " << i+2 << endl;
            moo << "2 " << i+1 << " " << i+2 << endl;
            moo << "1 " << i+1 << " " << i+2 << endl;
            moo << "2 " << i+1 << " " << i+2 << endl;
            moo << "1 " << i+1 << " " << i+2 << endl;
            moo << "2 " << i+1 << " " << i+2 << endl;
        }
    }
}
