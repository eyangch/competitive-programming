#include <bits/stdc++.h>
#define int long long

using namespace std;

struct segt{
    int vl, vr;
    segt *l, *r;
    int val, lazy;

    segt(int left, int right){
        vl = left; vr = right;
        val = lazy = 0;
        if(vl != vr){
            int vm = vl + (vr - vl) / 2;
            l = new segt(vl, vm);
            r = new segt(vm+1, vr);
        }
    }

    ~segt(){
        if(vl != vr){
            delete l;
            delete r;
        }
    }

    void push(){
        val += (vr - vl + 1) * lazy;
        if(vl != vr){
            l->lazy += lazy;
            r->lazy += lazy;
        }
        lazy = 0;
    }

    void upd(int left, int right, int dv){
        push();
        if(vl > vr || left > vr || right < vl){
            return;
        }
        if(vl >= left && vr <= right){
            lazy += dv;
            push();
        }else{
            l->upd(left, right, dv);
            r->upd(left, right, dv);
            val = l->val + r->val;
        }
    }

    int qry(int left, int right){
        if(vl > vr || vl > right || vr < left){
            return 0;
        }
        push();
        if(vl >= left && vr <= right){
            return val;
        }
        int q1 = l->qry(left, right);
        int q2 = r->qry(left, right);
        return q1+q2;
    }
};

int N, Q;
vector<int> graph[100000];
vector<int> ord;
int fo[100000], lo[100000];
segt *t;
set<int> cl[100000];

void dfs(int id, int par){
    fo[id] = ord.size();
    ord.push_back(id);
    for(int i : graph[id]){
        if(i != par){
            dfs(i, id);
        }
    }
    lo[id] = ord.size()-1;
}

int32_t main(){
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);
    cin >> N >> Q;
    for(int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    dfs(0, 0);
    t = new segt(0, N-1);
    int outputn = 0;
    for(int i = 0; i < Q; i++){
        int qid; cin >> qid;
        if(qid == 1){
            int x, c; cin >> x >> c;
            x--; c--;
            auto upit = cl[c].upper_bound(fo[x]);
            if(upit != cl[c].begin()){
                upit--;
                if(lo[ord[*upit]] >= lo[x]){
                    continue;
                }
            }
            t->upd(fo[x], lo[x], 1);
            vector<int> in;
            auto it = cl[c].lower_bound(fo[x]);
            for(; it != cl[c].end(); it++){
                if(*it > lo[x]) break;
                in.push_back(ord[*it]);
            }
            for(int j : in){
                t->upd(fo[j], lo[j], -1);
                cl[c].erase(fo[j]);
            }
            cl[c].insert(fo[x]);
        }else{
            outputn++;
            int x; cin >> x;
            x--;
            int ans = t->qry(fo[x], lo[x]);
            cout << ans << endl;
        }
    }
    delete t;
}
