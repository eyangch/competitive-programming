#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N, Q, C;
    cin >> N >> Q >> C;
    vector<ll> sky[100][100]; //x, y
    for(ll i = 0; i < N; i++){
        ll x, y, s;
        cin >> x >> y >> s;
        sky[x-1][y-1].push_back(s);
    }
    ll dp[11][101][101];
    fill(dp[0][0], dp[10][100] + 101, 0);
    for(ll i = 0; i < C + 1; i++){
        for(ll x = 0; x < 100; x++){
            for(ll y = 0; y < 100; y++){
                for(ll j : sky[x][y]){
                    dp[i][x][y] += j;
                }
                if(x > 0){
                    dp[i][x][y] += dp[i][x-1][y];
                }
                if(y > 0){
                    dp[i][x][y] += dp[i][x][y-1];
                }
                if(x > 0 && y > 0){
                    dp[i][x][y] -= dp[i][x-1][y-1];
                }
            }
        }
        for(ll x = 0; x < 100; x++){
            for(ll y = 0; y < 100; y++){
                for(ll j = 0; j < (ll)sky[x][y].size(); j++){
                    sky[x][y][j]++;
                    sky[x][y][j] %= C + 1;
                }
            }
        }
    }
    for(ll i = 0; i < Q; i++){
        ll T, x1, y1, x2, y2;
        cin >> T >> x1 >> y1 >> x2 >> y2;
        x1 -= 2;
        y1 -= 2;
        x2--;
        y2--;
        if(x1 < 0) x1 = 100;
        if(y1 < 0) y1 = 100;
        T %= C + 1;
        cout << dp[T][x2][y2] - dp[T][x1][y2] - dp[T][x2][y1] + dp[T][x1][y1] << endl;
    }
    return 0;
}
