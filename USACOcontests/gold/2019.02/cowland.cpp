/*
Solution: O((N+Q) logN) i think
Get first and last occurences of each vertex in dfs (flatten into array)
Maintain XOR Fenwick Tree/BIT on array
To update, update value on first and last occurences in BIT
To query the path from u to v, get the XOR value for the values before the first occurence of u and the first occurence of v.
XORing these two values together leaves only the subtree of the LCA (not including the LCA)
Note that any unused values (not on the path from u to v) are XORed twice, resulting in 0.
Then, since the LCA is still missing, XORing the LCA gives us the answer to the query (LCA is found in O(1) with sparse table.
*/

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int e[100000];
int depth[100000];
vector<int> graph[100000];
int BIT[300000];
int o1[100000], o2[100000];
int oe[100000];
int lg2[300000];
vector<int> etour;
int st[20][300000];
int up[100000][17];
int cntin = 0;

int idminf(int a, int b){
    return (depth[a] < depth[b] ? a : b);
}

int qry(int id){
    int ret = 0;
    for(; id > 0; id -= id&-id){
        ret ^= BIT[id];
    }
    return ret;
}

void upd(int id, int x, int og){
    int dv = x ^ og;
    for(; id <= cntin; id += id&-id){
        BIT[id] ^= dv;
    }
}

void dfs(int id, int par, int d){
    oe[id] = etour.size();
    etour.push_back(id);
    depth[id] = d;
    o1[id] = ++cntin;
    for(int i : graph[id]){
        if(i == par) continue;
        dfs(i, id, d+1);
        etour.push_back(id);
    }
    o2[id] = ++cntin;
}

int lca(int u, int v){
    int l = oe[u], r = oe[v];
    if(l > r) swap(l, r);
    int p2 = lg2[r-l+1];
    return idminf(st[p2][l], st[p2][r-(1<<p2)+1]);
}

signed main(){
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> e[i];
    }
    for(int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    dfs(0, 0, 0);
    for(int i = 0; i < N; i++){
        upd(o1[i], e[i], 0);
        upd(o2[i], e[i], 0);
    }
    lg2[1] = 0;
    for(int i = 2; i <= (int)etour.size(); i++){
        lg2[i] = lg2[i/2] + 1;
    }
    copy(etour.begin(), etour.end(), st[0]);
    for(int i = 1; i <= lg2[etour.size()]; i++){
        for(int j = 0; j + (1<<i) - 1 < (int)etour.size(); j++){
            st[i][j] = idminf(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i = 0; i < Q; i++){
        int x, j, v; cin >> x >> j >> v;
        j--;
        if(x == 1){
            upd(o1[j], v, e[j]);
            upd(o2[j], v, e[j]);
            e[j] = v;
        }else{
            v--;
            int curr = lca(j, v);
            int ans = 0;
            ans ^= qry(o1[j]) ^ qry(o1[v]) ^ e[curr];
            cout << ans << endl;
        }
    }
}
