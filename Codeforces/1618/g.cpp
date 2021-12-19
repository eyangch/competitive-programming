#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;

int N, M, A, Q;
int a[400000], r[400000], pfx[400001];
int par[400000], sz[400000], ac[400000], rv[400000], tot, ans[200000];
pair<int, int> q[200000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int p(int r, int s){
    return pfx[r+1] - pfx[r+1-s];
}

int find(int u){
    if(par[u] == u) return u;
    return (par[u] = find(par[u]));
}

void un(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v);
    tot -= p(rv[u], ac[u]) + p(rv[v], ac[v]);
    par[u] = v;
    sz[v] += sz[u];
    ac[v] += ac[u];
    rv[v] = max(rv[v], rv[u]);
    tot += p(rv[v], ac[v]);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M >> Q;
    A = N+M;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    for(int i = 0; i < M; i++){
        eat >> a[i+N];
    }
    iota(r, r+A, 0);
    sort(r, r+A, [](int x, int y){
        return a[x] < a[y];
    });
    sort(a, a+A);
    pfx[0] = 0;
    for(int i = 0; i < A; i++){
        pfx[i+1] = pfx[i] + a[i];
    }
    for(int i = 0; i < A-1; i++){
        pq.push({a[i+1] - a[i], i});
    }
    iota(par, par+A, 0);
    iota(rv, rv+A, 0);
    fill(sz, sz+A, 1);
    for(int i = 0; i < A; i++){
        ac[i] = (r[i] < N);
        tot += p(i, ac[i]);
    }
    for(int i = 0; i < Q; i++){
        eat >> q[i].f;
        q[i].s = i;
    }
    sort(q, q+Q);
    for(int i = 0; i < Q; i++){
        int K = q[i].f;
        while(!pq.empty() && pq.top().f <= K){
            int u = pq.top().s;
            pq.pop();
            un(u, u+1);
        }
        ans[q[i].s] = tot;
    }
    for(int i = 0; i < Q; i++) moo << ans[i] << endl;
}
