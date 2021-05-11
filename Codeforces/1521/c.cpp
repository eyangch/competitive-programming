#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, p[20000];

int qry(int t, int i, int j, int x){
    moo << "? " << t+1 << " " << i+1 << " " << j+1 << " " << x << endl;
    moo.flush();
    int ret;
    eat >> ret;
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        int mx = max(qry(0, 0, 1, N-1), qry(0, 1, 0, N-1));
        int mn = min(qry(1, 0, 1, 1), qry(1, 1, 0, 1));
        int num = qry(0, 0, 1, mx-1);
        int mxi = 0, mni = 0;
        if(num == mx-1){
            p[0] = mx, p[1] = mn;
            mxi = 0, mni = 1;
        }else{
            p[0] = mn, p[1] = mx;
            mni = 0, mxi = 1;
        }
        bool dft = (p[0] > N/2);
        for(int i = 2; i < N; i++){
            int cur = 0;
            if(dft == 0){
                cur = qry(0, 0, i, N-1);
            }else{
                cur = qry(1, i, 0, 1);
            }
            if(cur == p[0]){
                if(dft == 0){
                    cur = qry(1, i, 0, 1);
                }else{
                    cur = qry(0, 0, i, N-1);
                }
            }
            p[i] = cur;
        }
        moo << "! ";
        for(int i = 0; i < N; i++){
            moo << p[i] << " ";
        }
        moo << endl;
        moo.flush();
    }
}
