#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct sparse{
    vector<vector<int>> st;
    vector<int> lg2;
    void init(vector<int> a){
        lg2.push_back(0), lg2.push_back(0);
        for(int i = 2; i <= (int)a.size(); i++){
            lg2.push_back(lg2[i/2]+1);
        }
        for(int i = 0; i < lg2[a.size()]+1; i++){
            st.push_back(vector<int>());
        }
        st[0] = a;
        for(int i = 1; i < lg2[a.size()]+1; i++){
            for(int j= 0; j + (1<<i) - 1 < (int)a.size(); j++){
                st[i].push_back(max(st[i-1][j], st[i-1][j+(1<<(i-1))]));
            }
        }
    }
    int qry(int l, int r){
        int p2 = lg2[r-l+1];
        return max(st[p2][l], st[p2][r-(1<<p2)+1]);
    }
};

vector<sparse> st;
int N, W, pre[1000000];
vector<int> a[1000000];
set<int> active;
vector<int> de[1000000], re[1000000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> W;
    for(int i = 0; i < N; i++){
        int l; eat >> l;
        for(int j = 0; j < l; j++){
            int x; eat >> x;
            a[i].push_back(x);
        }
        sparse cur;
        cur.init(a[i]);
        st.push_back(cur);
        if(l-1 < W-l){
            de[l-1].push_back(i);
            re[W-l].push_back(i);
        }
        active.insert(i);
    }
    long long ans = 0;
    for(int i = 0; i < W; i++){
        for(int j : active){
            int r = i, l = a[j].size() - (W - i);
            ans -= pre[j];
            int cur = -1e9-5;
            if(r >= (int)a[j].size()){
                cur = 0;
                r = a[j].size()-1;
            }
            if(l < 0){
                cur = 0;
                l = 0;
            }
            cur = max(cur, st[j].qry(l, r));
            pre[j] = cur;
            ans += cur;
        }
        for(int j : de[i]){
            active.erase(j);
        }
        for(int j : re[i]){
            active.insert(j);
        }
        moo << ans << " ";
    }
    moo << endl;
}
