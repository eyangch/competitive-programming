#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K, dp[501];
bool a[500];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K;
    fill(dp, dp+N+1, -1);
    queue<int> q;
    dp[0] = 0;
    q.push(0);
    while(!q.empty()){
        int id = q.front();
        q.pop();
        for(int i = 0; i <= K; i++){
            int nxt = id + 2 * i - K;
            if(K - i > id || N - id < i || nxt < 0 || nxt > N || dp[nxt] != -1) continue;
            dp[nxt] = dp[id] + 1;
            q.push(nxt);
        }
    }
    if(dp[N] == -1){
        moo << -1 << endl;
        return 0;
    }
    stack<int> op;
    int cur = N;
    while(cur != 0){
        for(int i = 0; i <= K; i++){
            int prev = cur - (2 * i - K);
            if(K - i > prev || N - prev < i || prev < 0 || prev > N || dp[prev] != dp[cur] - 1) continue;
            op.push(i);
            cur = prev;
            break;
        }
    }
    int ans = 0;
    while(!op.empty()){
        int cop = op.top();
        op.pop();
        int add = cop, sub = K - cop;
        vector<int> addv, subv;
        for(int i = 0; add; i++){
            if(!a[i]){
                addv.push_back(i);
                add--;
            }
        }
        for(int i = 0; sub; i++){
            if(a[i]){
                subv.push_back(i);
                sub--;
            }
        }
        for(int i : addv) a[i] = 1;
        for(int i : subv) a[i] = 0;
        moo << '?';
        for(int i : addv) moo << ' ' << i+1;
        for(int i : subv) moo << ' ' << i+1;
        moo << endl;
        moo.flush();
        int x; eat >> x;
        ans ^= x;
    }
    moo << "! " << ans << endl;
}
