#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define double long double

using namespace std;

int N;
double x[100000], y[100000];

bool works(double mid){
    for(int i = 0; i < N; i++){
        if(2 * mid < y[i]) return false;
    }
    double l = -1e17, r = 1e17;
    for(int i = 0; i < N; i++){
        double dist = sqrt(pow(mid, 2) - pow(mid - y[i], 2));
        //moo << mid << " " << mid - y[i] << " " << dist << endl;
        l = max(l, x[i] - dist);
        r = min(r, x[i] + dist);
    }
    if(l <= r) return true;
    return false;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    moo << setprecision(16) << fixed;
    for(int i = 0; i < N; i++) eat >> x[i] >> y[i];
    bool yes[2] = {0, 0};
    for(int i = 0; i < N; i++){
        yes[y[i] > 0] = true;
    }
    if(yes[0] && yes[1]){
        moo << -1 << endl;
        return 0;
    }
    if(yes[0]){
        for(int i = 0; i < N; i++) y[i] = -y[i];
    }
    double lo = 0, hi = 1e17, mid = 0;
    while(hi - lo > 1e-9 * lo){
        mid = (lo + hi) * 0.5;
        if(works(mid)) hi = mid;
        else lo = mid;
    }
    moo << mid << endl;
}
