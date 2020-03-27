#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        ll N, K;
        cin >> N >> K;
        string ans;
        for(int i = 0; i < N; i++) ans += 'a';
        ll tri = ceil((sqrt(8 * K + 1) + 1) / 2 - 1);
        ans[N-tri - 1] = 'b';
        K -= (tri - 1) * (tri) / 2;
        ans[N - K] = 'b';
        cout << ans << endl;
    }
    return 0;
}
