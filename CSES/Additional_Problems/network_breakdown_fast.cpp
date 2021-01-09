#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int N, M, K;
gp_hash_table<long long, null_type, hash<long long>, equal_to<long long>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true>> broken({},{},{},{},{1<<17});
long long fix[200000], conn[200000];
int par[100000], sz[100000];
int components, ans[200000];

int find(int u){
    if(u == par[u]){
        return u;
    }
    par[u] = find(par[u]);
    return par[u];
}

void un(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return;
    }
    components--;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

void print(int x){
    int dv = 100000;
    while(true){
        if(x/dv > 0) break;
        dv /= 10;
    }
    while(dv > 0){
        int v = x/dv;
        x %= dv;
        dv /= 10;
        putchar_unlocked(v + '0');
    }
    putchar_unlocked(' ');
}

int getN(){
    char x;
    int ret = 0;
    while((x = getchar_unlocked()) < '0'){}
    while(x >= '0'){
        ret *= 10;
        ret += x-'0';
        x = getchar_unlocked();
    }
    return ret;
}

signed main(){
    N = getN();
    M = getN();
    K = getN();
    for(int i = 0; i < M; i++){
        int a = getN();
        int b = getN();
        if(--a > --b) swap(a, b);
        conn[i] = 200000LL*a+b;
    }
    for(int i = 0; i < K; i++){
        int a = getN();
        int b = getN();
        if(--a > --b) swap(a, b);
        fix[i] = 200000LL*a+b;
        broken.insert(fix[i]);
    }
    components = N;
    iota(par, par+N, 0);
    fill(sz, sz+N, 1);
    for(int i = 0; i < M; i++){
        if(broken.find(conn[i]) == broken.end()){
            un(conn[i]/200000LL, conn[i]%200000LL);
        }
    }
    for(int i = K-1; i >= 0; i--){
        ans[i] = components;
        un(fix[i]/200000LL, fix[i]%200000LL);
    }
    for(int i = 0; i < K; i++){
        print(ans[i]);
    }
    putchar_unlocked('\n');
}
