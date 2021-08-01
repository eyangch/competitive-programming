#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct sparse{
    int lg2[200001];
    int st[20][200000];
    int N;
    sparse(){
        lg2[0] = lg2[1] = 0;
        for(int i = 2; i <= 200000; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
    void init(int N, int (&ar)[200000]){
        this->N = N;
        copy(ar, ar+N, st[0]);
        for(int i = 1; i < 20; i++){
            for(int j = 0; j + (1<<i) - 1 < N; j++){
                st[i][j] = gcd(st[i-1][j], st[i-1][j+(1LL<<(i-1))]);
            }
        }
    }
    int qry(int l, int r){
        if(r < 0 || l >= N) return 0;
        int p2 = lg2[r-l+1];
        return gcd(st[p2][l], st[p2][r-(1LL<<p2)+1]);
    }
} *st;

int T, N, a[200000], p[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    st = new sparse();
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        for(int i = 0; i < N-1; i++){
            p[i] = abs(a[i+1] - a[i]);
        }
        int ans = 0, e = 0;
        st->init(N-1, p);
        for(int i = 0; i < N-1; i++){
            e = max(e, i);
            while(e < N-2 && st->qry(i, e+1) > 1){
                e++;
            }
            if(st->qry(i, e) > 1) ans = max(ans, e - i + 1);
        }
        moo << ans + 1 << endl;
    }
}
