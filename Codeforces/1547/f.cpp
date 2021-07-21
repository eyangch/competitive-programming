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
                st[i][j] = gcd(st[i-1][j], st[i-1][j+(1<<(i-1))]);
            }
        }
    }
    int qry(int l, int r){
        if(r < 0 || l >= N) return 0;
        int p2 = lg2[r-l+1];
        return gcd(st[p2][l], st[p2][r-(1<<p2)+1]);
    }
} *st;

int T, N, a[200000];

bool works(int x){
    int val = -1;
    for(int i = 0; i < N; i++){
        int l1 = i, r1 = min(N-1, i+x), l2 = 0, r2 = -1 + ((i+x >= N) * (1+(i+x)%N));
        int cur = gcd(st->qry(l1, r1), st->qry(l2, r2));
        if(val == -1) val = cur;
        else if(cur != val) return false;
    }
    return true;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    st = new sparse();
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        st->init(N, a);
        int lo = 0, hi = N, mid = 0, ans = 0;
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(works(mid)){
                ans = mid, hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        moo << ans << endl;
    }
}
