#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segt{
    int l, r, m;
    segt *a, *b;
    int v = 0, lz = 0;
    segt(int l, int r){
        this->l = l, this->r = r, m = (l+r)/2;
        if(l < r) a = new segt(l, m), b = new segt(m+1, r);
    }
    void push(){
        v = max(v, lz);
        if(l < r) a->lz = max(a->lz, lz), b->lz = max(b->lz, lz);
        lz = 0;
    }
    void upd(int l, int r, int v){
        push();
        if(this->l > r || this->r < l) return;
        if(this->l >= l && this->r <= r){
            lz = max(lz, v);
            push();
        }else{
            a->upd(l, r, v);
            b->upd(l, r, v);
            this->v = max(a->v, b->v);
        }
    }
    int qry(int l, int r){
        if(this->l > r || this->r < l) return 0;
        push();
        if(this->l >= l && this->r <= r){
            return v;
        }
        int q1 = a->qry(l, r);
        int q2 = b->qry(l, r);
        return max(q1, q2);
    }
};

int N, M;
vector<pair<int, int>> d1[300000];
int r[300000][3];
map<int, int> cm;
segt *s;
int dp[300000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    set<int> itm;
    for(int i = 0; i < M; i++){
        eat >> r[i][0] >> r[i][1] >> r[i][2];
        r[i][0]--, r[i][1]--, r[i][2]--;
        itm.insert(r[i][1]);
        itm.insert(r[i][2]);
    }
    int cnt = 0;
    for(int i : itm){
        cm[i] = cnt;
        cnt++;
    }
    for(int i = 0; i < M; i++){
        d1[r[i][0]].push_back({cm[r[i][1]], cm[r[i][2]]});
    }
    for(int i = 0; i < N; i++){
        sort(d1[i].begin(), d1[i].end());
    }
    s = new segt(0, (int)itm.size());
    for(pair<int, int> i : d1[0]){
        s->upd(i.first, i.second, 1);
    }
    dp[0] = 1;
    for(int i = 1; i < N; i++){
        int val = 0;
        for(pair<int, int> j : d1[i]){
            val = max(val, s->qry(j.first, j.second));
        }
        dp[i] = val+1;
        for(pair<int, int> j : d1[i]){
            s->upd(j.first, j.second, dp[i]);
        }
    }
    set<int> ans;
    for(int i = 0; i < N; i++) ans.insert(i);
    int mx = 0, mxi = 0;
    for(int i = 0; i < N; i++){
        if(dp[i] > mx){
            mx = dp[i], mxi = i;
        }
    }
    int id = mxi;
    while(true){
        ans.erase(id);
        if(dp[id] == 1) break;
        for(int i = id-1; true; i--){
            assert(i >= 0);
            if(dp[i] != dp[id]-1) continue;
            int i1 = 0, i2 = 0;
            bool good = false;
            while(i1 < (int)d1[id].size() && i2 < (int)d1[i].size()){
                pair<int, int> p1 = d1[id][i1], p2 = d1[i][i2];
                if(p1.first <= p2.second && p1.second >= p2.first){
                    good = true;
                    break;
                }
                if(p1.first > p2.second) i2++;
                else i1++;
            }
            if(good){
                id = i;
                break;
            }
        }
    }
    moo << ans.size() << endl;
    for(int i : ans){
        moo << i+1 << ' ';
    }
    moo << endl;
}
