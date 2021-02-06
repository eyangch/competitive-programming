#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

int N, Q, bg[200000], en[200000], cnt;
ll v[200000], BIT[700000];
vector<int> graph[200000];

void dfs(int id, int par){
    bg[id] = ++cnt;
    for(int i : graph[id]){
        if(i != par) dfs(i, id);
    }
    en[id] = cnt;
}

void upd(int id, ll x){
    for(int i = id; i <= N; i += i & -i){
        BIT[i] += x;
    }
}

static ll qry(int id){
    ll ret = 0;
    for(int i = id; i > 0; i -= i & -i){
        ret += BIT[i];
    }
    return ret;
}

int32_t main(){    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    dfs(0, -1);
    for(int i = 0; i < N; i++){
        upd(bg[i], v[i]);
    }
    for(int i = 0; i < Q; i++){
        int op; cin >> op;
        if(op == 1){
            int s, x; cin >> s >> x;
            ll diff = x - v[s-1];
            upd(bg[s-1], diff);
            v[s-1] = x;
        }else{
            int s; cin >> s;
            ll a = qry(en[s-1]) - qry(bg[s-1]-1);
            cout << a << endl;
        }
    }
}

