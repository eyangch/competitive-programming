#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

struct segt{
    int N, t[400001], s[400001];
    void push(int i){
        t[i] = t[i*2] + t[i*2+1];
        s[i] = min(s[i*2+1], s[i*2] + t[i*2+1]);
    }
    void upd(int x, int v, int i=1, int l=0, int r=100000){
        if(x < l || x > r) return;
        if(l == r) t[i] += v, s[i] += v;
        else upd(x, v, i*2, l, (l+r)/2), upd(x, v, i*2+1, (l+r)/2+1, r), push(i);
    }
} S;

int T, N, M, A[100000], sum[100000], tot[100000];
vector<int> B[100000];

int divc(int n, int d){
    return n/d + (n%d>0);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++){
            eat >> A[i];
            S.upd(A[i], 1);
        }
        for(int i = 0; i < M; i++){
            int K; eat >> K;
            B[i].clear();
            tot[i] = sum[i] = 0;
            for(int j = 0; j < K; j++){
                int b; eat >> b;
                B[i].push_back(b);
                sum[i] += b;
                tot[i]++;
            }
            S.upd(divc(sum[i], tot[i]), -1);
        }
        for(int i = 0; i < M; i++){
            S.upd(divc(sum[i], tot[i]), 1);
            for(int j = 0; j < tot[i]; j++){
                S.upd(divc(sum[i] - B[i][j], tot[i]-1), -1);
                moo << (S.s[1] >= 0);
                S.upd(divc(sum[i] - B[i][j], tot[i]-1), 1);
            }
            S.upd(divc(sum[i], tot[i]), -1);
        }
        moo << endl;
        for(int i = 0; i < N; i++) S.upd(A[i], -1);
        for(int i = 0; i < M; i++) S.upd(divc(sum[i], tot[i]), 1);
    }
}
