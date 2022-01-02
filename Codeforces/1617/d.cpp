#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, V[10000], A[10000];

int qry(int a, int b, int c){
    moo << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
    moo.flush();
    int ret; eat >> ret;
    if(ret == -1) exit(69420);
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i += 3){
            V[i/3] = qry(i, i+1, i+2);
        }
        int C = -1, I = -1;
        for(int i = 1; i < N/3; i++){
            if(V[i] != V[i-1]){
                int q[] = {V[i-1], qry(i*3-2, i*3-1, i*3), qry(i*3-1, i*3, i*3+1), V[i]};
                for(int j = 0; j < 3; j++){
                    if(q[j] != q[j+1]){
                        I = (i-1)*3+j, C = i*3+j;
                        if(q[j]) swap(C, I);
                    }
                }
                break;
            }
        }
        assert(~C | ~I);
        A[C] = 1, A[I] = 0;
        for(int i = 0; i < N/3; i++){
            int x = i*3;
            if((C >= x && C < x + 3) || (I >= x && I < x + 3)){
                for(int j = 0; j < 3; j++){
                    if(x+j == C || x+j == I) continue;
                    A[x+j] = qry(x+j, C, I);
                }
                continue;
            }
            if(V[i]){
                int q = qry(I, x, x+1);
                if(q){
                    A[x] = A[x+1] = 1;
                    A[x+2] = qry(I, C, x+2);
                }else{
                    A[x+2] = 1;
                    A[x] = qry(I, C, x);
                    A[x+1] = !A[x];
                }
            }else{
                int q = qry(C, x, x+1);
                if(q){
                    A[x+2] = 0;
                    A[x] = qry(I, C, x);
                    A[x+1] = !A[x];
                }else{
                    A[x] = A[x+1] = 0;
                    A[x+2] = qry(I, C, x+2);
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < N; i++) if(!A[i]) ans.push_back(i+1);
        moo << "! " << ans.size();
        for(int i : ans) moo << ' ' << i;
        moo << endl;
        moo.flush();
    }
}
