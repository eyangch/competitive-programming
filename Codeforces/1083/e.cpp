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
};

int N;
Rect R[1000000];
int dp[1000000];

int get_y(Line l, int x){
    return l.m * x + l.c;
}

bool isct(Line a, Line b, Line c){
    // true if a intersect b before c
    int n1 = b.c - a.c;
    int n2 = c.c - a.c;
    int d1 = a.m - b.m;
    int d2 = a.m - c.m;
    return ((__int128)n1 * d2) < ((__int128)n2 * d1);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> R[i].x >> R[i].y >> R[i].a;
    }
    sort(R, R+N, [](Rect a, Rect b){
        return a.x < b.x;
    });
    deque<Line> dq;
    for(int i = 0; i < N; i++){
        int cy = R[i].y;
        int mxv = 0;
        while(dq.size() >= 2 && get_y(dq[dq.size()-2], cy) >= get_y(dq.back(), cy)){
            dq.pop_back();
        }
        if(!dq.empty()){
            mxv = max(0LL, get_y(dq.back(), cy));
        }
        if(i > 0) dp[i] = dp[i-1];
        dp[i] = max(dp[i], R[i].x * cy - R[i].a + mxv);
        Line cur = {-R[i].x, dp[i]};
        while(dq.size() >= 2 && !isct(cur, dq[0], dq[1])){
            dq.pop_front();
        }
        dq.push_front(cur);
    }
    moo << dp[N-1] << endl;
}