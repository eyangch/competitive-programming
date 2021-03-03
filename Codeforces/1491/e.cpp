#include <bits/stdc++.h>
#define endl "\n"
#define moo cout

using namespace std;

int N, c[200000], fib[30], rfib[1000000];
vector<int> graph[200000];
bool no[200000];

int dfs(int id, int par){
    if(no[id]) return 0;
    c[id] = 1;
    for(int i : graph[id]){
        if(i != par){
            c[id] += dfs(i, id);
        }
    }
    return c[id];
}

void dfs2(int id, int par, vector<int> &v){
    if(no[id]) return;
    v.push_back(id);
    for(int i : graph[id]){
        if(i != par){
            dfs2(i, id, v);
        }
    }
}

bool fibt(vector<int> &cur){
    if((int)cur.size() < 4) return true;
    int cfib = rfib[cur.size()];
    bool ret = false;
    dfs(cur[0], -1);
    for(int i : cur){
        for(int j : graph[i]){
            if(c[i] < c[j] || no[j]) continue;
            if(c[j] == fib[cfib-1] || c[j] == fib[cfib-2]){
                vector<int> nxt1, nxt2;
                dfs2(j, i, nxt1);
                for(int k : nxt1) no[k] = true;
                for(int k : cur){
                    if(!no[k]) nxt2.push_back(k);
                }
                int ok = true;
                ok &= fibt(nxt2);
                for(int k : nxt1) no[k] = false;
                for(int k : nxt2) no[k] = true;
                ok &= fibt(nxt1);
                for(int k : nxt2) no[k] = false;
                ret |= ok;
                goto found;
            }
        }
    }
    found:
    return ret;
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 30; i++){
        fib[i] = fib[i-1] + fib[i-2];
        rfib[fib[i]] = i;
    }
    vector<int> cur;
    for(int i = 0; i < N; i++) cur.push_back(i);
    moo << (fibt(cur) ? "yES" : "nO") << endl;
}
