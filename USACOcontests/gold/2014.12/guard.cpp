#include <bits/stdc++.h>
#define int long long

using namespace std;

struct cow{int h; int w; int s;};

int N, H;
cow c[20];
int dp[1<<20];

void dpf(){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int id = q.front();
        q.pop();
        for(int i = 0; i < N; i++){
            int nid = id|(1<<i);
            if(dp[nid] == -1e9){
                q.push(nid);
            }
            dp[nid] = max(dp[nid], min(c[i].s, dp[id]-c[i].w));
        }
    }
}

int32_t main(){
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    cin >> N >> H;
    for(int i = 0; i < N; i++){
        cin >> c[i].h >> c[i].w >> c[i].s;
    }
    fill(dp, dp+(1<<N), -1e9);
    dp[0] = 1e9;
    dpf();
    int ans = -1;
    for(int i = 1; i < (1<<N); i++){
        if(dp[i] > -1e9){
            int hsum = 0;
            for(int j = 0; j < N; j++){
                if(i&(1<<j)) hsum += c[j].h;
            }
            if(hsum >= H){
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ((ans >= 0) ? to_string(ans) : "Mark is too tall") << endl;
}
