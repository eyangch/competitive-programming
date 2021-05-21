#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define f first
#define s second

using namespace std;

int T, N, M, x[300000], id[300000];
char c[300000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++){
            eat >> x[i];
        }
        for(int i = 0; i < N; i++){
            eat >> c[i];
        }
        iota(id, id+N, 0);
        sort(id, id+N, [](int a, int b){
            return x[a] < x[b];
        });
        stack<int> s[2];
        queue<int> q[2];
        int ans[N];
        fill(ans, ans+N, -1);
        for(int i = 0; i < N; i++){
            int cur = id[i], pol = x[cur] % 2;
            if(c[cur] == 'R'){
                s[pol].push(cur);
            }else{
                if(s[pol].empty()){
                    q[pol].push(cur);
                }else{
                    int col = s[pol].top();
                    s[pol].pop();
                    ans[cur] = ans[col] = (x[cur] - x[col]) / 2;
                }
            }
        }
        for(int i = 0; i < 2; i++){
            while((int)s[i].size() >= 2){
                int col1 = s[i].top(); s[i].pop();
                int col2 = s[i].top(); s[i].pop();
                int x1 = M + M - x[col1], x2 = x[col2];
                ans[col1] = ans[col2] = (x1 - x2) / 2;
            }
        }
        for(int i = 0; i < 2; i++){
            while((int)q[i].size() >= 2){
                int col1 = q[i].front(); q[i].pop();
                int col2 = q[i].front(); q[i].pop();
                int x1 = -x[col1], x2 = x[col2];
                ans[col1] = ans[col2] = (x2 - x1) / 2;
            }
        }
        for(int i = 0; i < 2; i++){
            if(q[i].size() && s[i].size()){
                int c1 = q[i].front(), c2 = s[i].top();
                ans[c1] = ans[c2] = (M + M - x[c2] + x[c1]) / 2;
            }
        }
        for(int i = 0; i < N; i++){
            moo << ans[i] << " ";
        }
        moo << endl;
    }
}
