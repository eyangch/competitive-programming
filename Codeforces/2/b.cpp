#include <bits/stdc++.h>

using namespace std;

int N;
int p2[1000][1000], p5[1000][1000];
int dp2[1000][1000], dp5[1000][1000];
int zx = -1, zy = -1;

int lg(int x, int b){
    if(!x) return 1e6;
    int ans = 0;
    while(x % b == 0){
        ans++;
        x /= b;
    }
    return ans;
}

string backtrack(int (&p)[1000][1000], int (&dp)[1000][1000]){
    int x = N-1, y = N-1;
    string res;
    while(x > 0 || y > 0){
        if(x > 0){
            if(dp[x-1][y] == dp[x][y] - p[x][y]){
                x--;
                res += 'D';
                continue;
            }
        }
        if(y > 0){
            if(dp[x][y-1] == dp[x][y] - p[x][y]){
                y--;
                res += 'R';
                continue;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x; cin >> x;
            p2[i][j] = lg(x, 2);
            p5[i][j] = lg(x, 5);
            int a = 1e9, b = 1e9;
            if(i > 0) a = min(a, dp2[i-1][j]), b = min(b, dp5[i-1][j]);
            if(j > 0) a = min(a, dp2[i][j-1]), b = min(b, dp5[i][j-1]);
            if(a == 1e9) a = 0, b = 0;
            dp2[i][j] = p2[i][j] + a;
            dp5[i][j] = p5[i][j] + b;
            if(!x) zx = i, zy = j;
            //cout << dp2[i][j] << " ";
        }//cout << endl;
    }
    string ans;
    int nans = 0;
    if(dp2[N-1][N-1] < dp5[N-1][N-1]){
        ans = backtrack(p2, dp2);
        nans = dp2[N-1][N-1];
    }else{
        ans = backtrack(p5, dp5);
        nans = dp5[N-1][N-1];
    }
    if(nans > 1 && zx >= 0){
        nans = 1;
        ans = "";
        for(int i = 0; i < zx; i++){
            ans += 'D';
        }
        for(int i = 0; i < zy; i++){
            ans += 'R';
        }
        for(int i = zx+1; i < N; i++){
            ans += 'D';
        }
        for(int i = zy+1; i < N; i++){
            ans += 'R';
        }
    }
    cout << nans << endl << ans << endl;
}
