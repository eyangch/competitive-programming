#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N;

int qry(int x1, int y1, int x2, int y2){
    if(x1 < 1 || y1 < 1 || x1 > N || y1 > N) return 0;
    if(x2 < 1 || y2 < 1 || x2 > N || y2 > N) return 0;
    moo << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    moo.flush();
    int ret; eat >> ret;
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    int lo = 1, hi = N, mid = 0, ans = 0;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(qry(1, 1, mid, N) == 0) lo = mid+1;
        else ans = mid, hi = mid-1;
    }
    int rb1 = ans;
    lo = 1, hi = rb1;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(qry(mid, 1, rb1, N) == 0) hi = mid-1;
        else ans = mid, lo = mid+1;
    }
    int lb1 = ans;
    lo = 1, hi = N;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(qry(lb1, 1, rb1, mid) == 0) lo = mid+1;
        else ans = mid, hi = mid-1;
    }
    int bb1 = ans;
    lo = 1, hi = bb1;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(qry(lb1, mid, rb1, bb1) == 0) hi = mid-1;
        else ans = mid, lo = mid+1;
    }
    int ub1 = ans;
    int lb2 = 1, rb2 = N, ub2 = 1, bb2 = N;
    if(qry(rb1+1, 1, N, N)) lb2 = rb1+1;
    else if(qry(1, bb1+1, N, N)) ub2 = bb1+1;
    else if(qry(1, 1, N, ub1-1)) bb2 = ub1-1;
    else if(qry(1, 1, lb1-1, N)) rb2 = lb1-1;
    lo = lb2, hi = rb2;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(qry(lb2, ub2, mid, bb2) == 0) lo = mid+1;
        else ans = mid, hi = mid-1;
    }
    rb2 = ans;
    lo = lb2, hi = rb2;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(qry(mid, ub2, rb2, bb2) == 0) hi = mid-1;
        else ans = mid, lo = mid+1;
    }
    lb2 = ans;
    lo = ub2, hi = bb2;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(qry(lb2, ub2, rb2, mid) == 0) lo = mid+1;
        else ans = mid, hi = mid-1;
    }
    bb2 = ans;
    lo = ub2, hi = bb2;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(qry(lb2, mid, rb2, bb2) == 0) hi = mid-1;
        else ans = mid, lo = mid+1;
    }
    ub2 = ans;
    moo << "! " << lb1 << " " << ub1 << " " << rb1 << " " << bb1 << " " << lb2 << " " << ub2 << " " << rb2 << " " << bb2 << endl;
}
