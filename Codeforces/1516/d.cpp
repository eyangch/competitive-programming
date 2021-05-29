#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, Q, a[100000], rch[100000], depth[100001], up[20][100001];
bool sieve[100001];
set<int> pf[100000];
vector<int> graph[100001];

void dfs(int id){
    for(int i = 1; i < 20; i++){
        up[i][id] = up[i-1][up[i-1][id]];
    }
    for(int i : graph[id]){
        depth[i] = depth[id] + 1;
        up[0][i] = id;
        dfs(i);
    }
}

int jump(int id, int d){
    for(int i = 0; i < 20; i++) if((d>>i)&1) id = up[i][id];
    return id;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    fill(sieve+2, sieve+100001, true);
    for(int i = 2; i <= 100000; i++){
        if(sieve[i]){
            for(int j = 2*i; j <= 100000; j += i){
                sieve[j] = false;
            }
        }
    }
    eat >> N >> Q;
    for(int i = 0; i < N; i++){
        eat >> a[i];
        int x = a[i];
        for(int j = 2; j * j <= a[i]; j++){
            if(x % j) continue;
            pf[i].insert(j);
            while(x % j == 0){
                x /= j;
            }
        }
        if(x > 1) pf[i].insert(x);
    }
    set<int> cur;
    for(int i = 0, e = 0; i < N; i++){
        while(e < N){
            bool good = true;
            for(int j : pf[e]) if(cur.count(j)) good = false;
            if(!good) break;
            for(int j : pf[e]) cur.insert(j);
            e++;
        }
        rch[i] = e;
        graph[e].push_back(i);
        for(int j : pf[i]) cur.erase(j);
    }
    depth[N] = 0;
    up[0][N] = N;
    dfs(N);
    while(Q--){
        int l, r; eat >> l >> r;
        l--, r--;
        int ans = 0;
        for(int i = 19; i >= 0; i--){
            if(up[i][l] <= r){
                l = up[i][l], ans += (1<<i);
            }
        }
        moo << ans+1 << endl;
    }
}
