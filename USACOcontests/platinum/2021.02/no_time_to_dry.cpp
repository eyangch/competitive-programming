#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;

struct BIT{
    int BIT[200001];
    int qry(int i){
        int sum = 0;
        for(i++; i > 0; i -= i & -i) sum += BIT[i];
        return sum;
    }
    void upd(int i, int x){
        for(i++; i <= 200000; i += i & -i) BIT[i] += x;
    }
};

int N, Q, a[200000], id[200000], ans[200000], spt[200000];
vector<int> seg[200000];
pair<pair<int, int>, int> qr[200000];
BIT bit;

int32_t main(){
    //freopen("no_time_to_dry.in", "r", stdin); freopen("no_time_to_dry.out", "w", stdout);
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Q;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    for(int i = 0; i < Q; i++){
        eat >> qr[i].f.f >> qr[i].f.s;
        qr[i].f.f--, qr[i].f.s--;
        qr[i].s = i;
    }
    sort(qr, qr+Q);
    stack<pair<int, int>> s;
    int cur = 0;
    for(int i = 0; i < N; i++){
        while(!s.empty() && s.top().f > a[i]){
            s.pop();
        }
        if(s.empty() || s.top().f < a[i]){
            id[i] = cur++;
            s.push({a[i], id[i]});
        }else{
            id[i] = s.top().s;
        }
        seg[id[i]].push_back(i);
    }
    for(int i = 0; i < cur; i++){
        spt[i] = 0;
        bit.upd(seg[i][0], 1);
    }
    int prev = 0;
    for(int i = 0; i < Q; i++){
        for(int j = prev; j < qr[i].f.f; j++){
            int x = id[j];
            bit.upd(seg[x][spt[x]], -1);
            if(++spt[x] < (int)seg[x].size()){
                bit.upd(seg[x][spt[x]], 1);
            }
        }
        prev = qr[i].f.f;
        ans[qr[i].s] = bit.qry(qr[i].f.s);
    }
    for(int i = 0; i < Q; i++){
        moo << ans[i] << endl;
    }
}
