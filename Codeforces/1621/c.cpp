#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, qc = -1, P[10000], vis[10000], idx[10000];

int qry(int i){
    moo << "? " << i+1 << endl;
    moo.flush();
    int r; eat >> r;
    if(!r) exit(69420);
    qc++;
    return r-1;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        qc = -2;
        vector<vector<int>> cyc;
        fill(vis, vis+N, -1);
        fill(idx, idx+N, 0);
        for(int i = 0; i < N; i++){
            int x = qry(i);
            if(~vis[x]){
                int loc = vis[x];
                int sz = cyc[loc].size();
                int id = ((idx[x]-qc)%sz+sz)%sz;
                //moo << i << ' ' << x << ' ' << id << ' ' << idx[x] << ' ' << qc << endl;
                P[i] = cyc[loc][id];
                continue;
            }
            vector<int> cur;
            cur.push_back(x);
            int y = qry(i);
            while(y != x){
                cur.push_back(y);
                y = qry(i);
            }
            int sz = cur.size();
            vector<int> ofst;
            for(int j = -qc; j < -qc + sz; j++){
                ofst.push_back(cur[((j)%sz+sz)%sz]);
            }
            P[i] = ofst[0];
            for(int j : ofst){
                vis[j] = cyc.size();
            }
            for(int j = 0; j < sz; j++){
                idx[ofst[j]] = j;
            }
            cyc.push_back(ofst);
        }
        moo << '!';
        for(int i = 0; i < N; i++){
            moo << ' ' << P[i]+1;
        }
        moo << endl;
        moo.flush();
    }
}
