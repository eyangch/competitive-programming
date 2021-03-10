#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N;
vector<double> m, d;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        m.clear(), d.clear();
        eat >> N;
        for(int i = 0; i < 2 * N; i++){
            int x, y; cin >> x >> y;
            if(x == 0) m.push_back(abs(y));
            else d.push_back(abs(x));
        }
        sort(m.begin(), m.end());
        sort(d.begin(), d.end());
        long double ans = 0;
        for(int i = 0; i < N; i++){
            ans += sqrt(m[i] * m[i] + d[i] * d[i]);
        }
        moo << fixed << setprecision(15) << ans << endl;
    }
}
