/*
ID: sireric1
LANG: C++14
TASK: fc
*/
#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define f first
#define s second

using namespace std;
typedef pair<double, double> pii;

int N;
pii pt[10000];

double ccw(pii a, pii b, pii c){
    return a.f * (b.s - c.s) + b.f * (c.s - a.s) + c.f * (a.s - b.s);
}

double dist(pii a, pii b){
    return sqrt((a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> pt[i].f >> pt[i].s;
    }
    sort(pt, pt+N);
    vector<pii> up, dn;
    for(int i = 0; i < N; i++){
        while(up.size() >= 2 && ccw(up[up.size()-2], up[up.size()-1], pt[i]) >= -0.001) up.pop_back();
        up.push_back(pt[i]);
        while(dn.size() >= 2 && ccw(dn[dn.size()-2], dn[dn.size()-1], pt[i]) <= 0.001) dn.pop_back();
        dn.push_back(pt[i]);
    }
    double ans = 0;
    for(int i = 1; i < (int)up.size(); i++){
        ans += dist(up[i-1], up[i]);
    }
    for(int i = 1; i < (int)dn.size(); i++){
        ans += dist(dn[i-1], dn[i]);
    }
    moo << fixed << setprecision(2) << ans << endl;
}
