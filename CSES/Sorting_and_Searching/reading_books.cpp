#include <bits/stdc++.h>

using namespace std;

long long N, tsum = 0, mx = 0;

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        long long t; cin >> t;
        tsum += t;
        mx = max(mx, t);
    }
    cout << max(tsum, tsum + (mx - (tsum-mx))) << endl;
}
