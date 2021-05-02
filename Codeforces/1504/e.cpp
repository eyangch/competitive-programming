#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define f first
#define s second
#define int long long

using namespace std;
typedef pair<int, int> pii;

int N;
pii c[100000];
int nxt[100000];
int di[1000000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> c[i].f >> c[i].s;
    }
    sort(c, c+N);
    for(int i = 0; i < N; i++){
        int targ = c[i].f + c[i].s;
        nxt[i] = upper_bound(c, c+N, pii(targ, 1e9)) - c - 1;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    fill(di, di+N, 1e9);
    di[0] = 0;
    while(!pq.empty()){
        int id = pq.top().s, d = pq.top().f;
        pq.pop();
        if(di[id] != d) continue;
        if(id > 0 && di[id-1] > d){
            di[id-1] = d;
            pq.push({d, id-1});
        }
        if(di[nxt[id]] > d){
            di[nxt[id]] = d;
            pq.push({d, nxt[id]});
        }
        if(nxt[id] < N-1 && di[nxt[id]+1] > d+c[nxt[id]+1].f - c[id].f - c[id].s){
            di[nxt[id]+1] = d+c[nxt[id]+1].f - c[id].f - c[id].s;
            pq.push({di[nxt[id]+1], nxt[id]+1});
        }
    }
    int ans = di[N-1];
    for(int i = 0; i < N; i++){
        ans += c[i].s;
    }
    moo << ans << endl;
}
