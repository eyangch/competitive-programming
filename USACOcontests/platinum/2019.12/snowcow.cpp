/*
Solution: O(N + Q logN)
First get preorder traversal of tree (all subtrees are contiguous) and store the start and end of each subtree (do a dfs in O(N) time).
To process the queries, we can do some range update range sum stuff with lazy segment trees (update = O(log N), query = O(log N))
In order to color the subtree of a node (snowball), we can maintain a set for each color with disjoint subtrees (sorted by its starting point / parent node).
If the subtree (sorted by starting point / parent node) in the set with the query's color immediately to the left of the node to be painted extends past the current node's subtree end, then the node and its subtree has already been painted the desired color.
If not, then we can start painting the subtree. We first do a range update from the start to the end of the subtree of the node to be colored incrementing by 1.
Then, we have to subtract all of the subtrees (note that they are all disjoint) that are already painted the current color.
We can iterate through the set for the current color (starting and ending at the bounds of the subtree of the node to be colored) and do a range update for each of those subtrees decrementing by one (cancelling the color operation on nodes that have already been colored).
Because our current node's subtree covers all of the subtrees in the set that we have done a range update for, we can remove those from the set and only add the current node's subtree to the set.
To get the colorfulness of the subtree of snowball x, we can simply get a range sum from the beginning to the end of the subtree of x using the segment tree.
*/

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
            int x; cin >> x;
            x--;
            cout << t->qry(fo[x], lo[x]) << endl;
        }
    }
    delete t;
}
