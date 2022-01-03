#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        int mnl = 1e15, mnr = -1, mnc = 0, mni = -1, mxr = -1, mxl = 1e15, mxc = 0;
        int mxi = -1;
        int bl = 1e15, br = -1, bc = 0;
        for(int i = 0; i < N; i++){
            int L, C, R; eat >> L >> R >> C;
            if(make_pair(L, C) < make_pair(mnl, mnc)){
                mnl = L, mnr = R, mnc = C, mni = i;
            }
            if(make_pair(-R, C) < make_pair(-mxr, mxc)){
                mxr = R, mxc = C, mxl = L, mxi = i;
            }
            if(make_pair(L, make_pair(-R, C)) < make_pair(bl, make_pair(-br, bc))){
                bl = L, br = R, bc = C;
            }
            if(br == mxr && bl == mnl) moo << min(bc, mxc + mnc) << endl;
            else moo << mxc + mnc << endl;
        }
    }
}
