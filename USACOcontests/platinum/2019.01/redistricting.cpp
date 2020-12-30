#include <bits/stdc++.h>

using namespace std;

int N, K;
int dif[300000];
int dp[300000];
char p[300000];

int32_t main(){
    freopen("redistricting.in", "r", stdin);
    freopen("redistricting.out", "w", stdout);
    scanf("%d%d%s", &N, &K, p);
    multiset<pair<int, int>> cur;
    for(int i = 0; i < N; i++){
        if(p[i] == 'H') dif[i] = 1;
        else dif[i] = -1;
        if(i > 0){
            dif[i] += dif[i-1];
            pair<int, int> bf = *cur.begin();
            dp[i] = bf.first + (dif[i] - bf.second <= 0);
        }if(i < K){
            dp[i] = (dif[i] <= 0);
        }
        cur.insert({dp[i], dif[i]});
        if(i >= K){
            cur.erase(cur.find({dp[i-K], dif[i-K]}));
        }
    }
    printf("%d\n", dp[N-1]);
}
