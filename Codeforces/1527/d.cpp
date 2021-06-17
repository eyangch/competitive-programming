#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, de[200000], su[200000], ans[200001], up[20][200000], l[200000], r[200000], c0[200000];
vector<int> graph[200000];

int dfs(int id, int par, int d, int c){
    if(c == 0) c = id;
    de[id] = d;
    su[id] = 1;
    c0[id] = c;
    for(int i = 1; i < 20; i++){
        up[i][id] = up[i-1][up[i-1][id]];
    }
    for(int i : graph[id]){
        if(i == par) continue;
        up[0][i] = id;
        su[id] += dfs(i, id, d+1, c);
    }
    return su[id];
}

bool is_ancestor(int u, int v){
    if(de[u] < de[v]) swap(u, v);
    for(int i = 19; i >= 0; i--){
        if(de[up[i][u]] >= de[v]) u = up[i][u];
    }
    return (u == v);
}

int jump(int u, int d){
    for(int i = 0; i < 20; i++){
        if((d >> i) & 1) u = up[i][u];
    }
    return u;
}

int lca(int u, int v){
    if(de[u] < de[v]) swap(u, v);
    u = jump(u, de[u] - de[v]);
    for(int i = 19; i >= 0; i--){
        if(up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    }
    return up[0][u];
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) graph[i].clear();
        for(int i = 0; i < N-1; i++){
            int u, v; eat >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        up[0][0] = 0;
        dfs(0, -1, 0, 0);
        fill(ans, ans+N+1, 0);
        for(int i : graph[0]){
            ans[0] += (su[i] * (su[i]-1)) / 2;
        }
        if((int)graph[0].size() == 1){
            ans[1] = su[0] - su[1] - 1;
            int mxd = 1;
            for(int i = 2; i <= N; i++){
                if(!is_ancestor(i, mxd) || i == N){
                    ans[i] = su[mxd];
                    break;
                }
                if(de[i] > de[mxd]){
                    ans[i] = su[mxd] - su[i];
                    mxd = i;
                }
            }
            for(int i = 0; i < N+1; i++) moo << ans[i] << " ";
            moo << endl;
            continue;
        }
        fill(l, l+N, -1);
        fill(r, r+N, -1);
        l[0] = r[0] = 0;
        for(int i = 1; i < N; i++){
            if(is_ancestor(l[i-1], i) && lca(r[i-1], i) == 0){
                l[i] = l[i-1], r[i] = r[i-1];
                if(de[i] > de[l[i-1]]){
                    l[i] = i;
                }
            }else if(is_ancestor(r[i-1], i) && lca(l[i-1], i) == 0){
                l[i] = l[i-1], r[i] = r[i-1];
                if(de[i] > de[r[i-1]]){
                    r[i] = i;
                }
            }else{
                break;
            }
        }
        vector<int> c1;
        int sum1 = 0;
        for(int i : graph[0]){
            if(is_ancestor(i, 1)){
                c1.push_back(su[i] - su[1]);
            }else{
                c1.push_back(su[i]);
            }
        }
        sum1 = accumulate(c1.begin(), c1.end(), 1);
        for(int i : c1){
            sum1 -= i;
            ans[1] += i * sum1;
        }
        for(int i = 2; i <= N; i++){
            if(i == N || l[i] == -1){
                int sur = su[r[i-1]];
                if(r[i-1] == 0){
                    sur = su[0] - su[c0[l[i-1]]];
                }
                ans[i] = su[l[i-1]] * sur;
                break;
            }
            int lb = 0, ub = 0, ob = 0;
            if(l[i-1] != l[i]){
                lb = l[i-1], ub = l[i], ob = r[i];
            }
            if(r[i-1] != r[i]){
                lb = r[i-1], ub = r[i], ob = l[i];
            }
            int m2 = su[ob];
            if(ob == 0){
                m2 -= su[c0[lb]];
            }
            if(is_ancestor(lb, ob) && ob != 0){
                int csum = su[lb];
                if(lb == 0){
                    csum -= su[c0[ob]];
                }
                ans[i] = m2 * (csum - su[ub]);
            }else{
                ans[i] = m2 * (su[lb] - su[ub]);
            }
        }
        for(int i = 0; i < N+1; i++) moo << ans[i] << " ";
        moo << endl;
    }
}
