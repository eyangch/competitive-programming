#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct Rect{
    int x, y, a;
};

struct Line{
    int m, c;
    int ev(int x){
        return m * x + c;
    }
};

struct LiChao{
    Line A[4000050];
    int yc[1000000];
    int N;
    void init(int n){
        N = n;
    }
    void upd(Line seg, int l=0, int r=-1, int i=1){
        if(r == -1) r = N-1;
        if(l == r){
            if(seg.ev(yc[l]) > A[i].ev(yc[l])){
                A[i] = seg;
            }
            return;
        }
        int mid = (l+r)/2;
        if(A[i].m > seg.m) swap(A[i], seg);
        if(A[i].ev(yc[mid]) >= seg.ev(yc[mid])){
            upd(seg, mid+1, r, i*2+1);
        }else{
            swap(A[i], seg);
            upd(seg, l, mid, i*2);
        }
    }
    int qry(int x, int l=0, int r=-1, int i=1){
        if(r == -1) r = N-1;
        if(l == r) return A[i].ev(yc[x]);
        int mid = (l+r)/2;
        if(x < mid){
            return max(A[i].ev(yc[x]), qry(x, l, mid, i*2));
        }else{
            return max(A[i].ev(yc[x]), qry(x, mid+1, r, i*2+1));
        }
    }
};

int N, dp[1000000];
Rect R[1000000];
LiChao seg;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    seg.init(N);
    for(int i = 0; i < N; i++){
        eat >> R[i].x >> R[i].y >> R[i].a;
        seg.yc[i] = R[i].y;
    }
    sort(seg.yc, seg.yc+N);
    sort(R, R+N, [](Rect a, Rect b){
        return a.x < b.x;
    });
    for(int i = 0; i < N; i++){
        int mxv = seg.qry(lower_bound(seg.yc, seg.yc+N, R[i].y) - seg.yc);
        if(i) dp[i] = dp[i-1];
        dp[i] = max(dp[i], R[i].x * R[i].y - R[i].a + mxv);
        seg.upd({-R[i].x, dp[i]});
    }
    moo << dp[N-1] << endl;
}