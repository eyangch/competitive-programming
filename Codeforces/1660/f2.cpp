#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

struct BIT{
    int bit[700000], N;
    void init(int N){
        fill(bit, bit+N+1, 0);
        this->N = N;
    }
    void upd(int i, int v){
        for(; i <= N; i += i & -i){
            bit[i] += v;
        }
    }
    int qry(int i){
        int ret = 0;
        for(; i > 0; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }
};

int T, N;
string s;
BIT b[3];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> s;
        int c = N+1, ans = 0;
        for(int i = 0; i < 3; i++){
            b[i].init(3*N);
        }
        for(int i = 0; i < N; i++){
            b[c%3].upd(c, 1);
            c += (s[i] == '+' ? -1 : 1);
            ans += b[c%3].qry(c);
        }
        moo << ans << endl;
    }
}
