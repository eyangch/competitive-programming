#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define f first
#define s second
#define int long long
#define double long double

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, pair<int, int>> pdi;

int N;
pii d[100000];
bool cr[100000];
int p[100000], n[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> d[i].f >> d[i].s;
    }
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    for(int i = 1; i < N; i++){
        if(d[i].s == d[i-1].s) continue;
        double val = ((double)(d[i].f - d[i-1].f)) / (d[i-1].s - d[i].s);
        if(val < 0) continue;
        pq.push({val, {i-1, i}});
    }
    for(int i = 0; i < N; i++){
        p[i] = i-1, n[i] = i+1;
    }
    while(!pq.empty()){
        double t = pq.top().f;
        int i1 = pq.top().s.f, i2 = pq.top().s.s;
        pq.pop();
        if(cr[i1] || cr[i2]) continue;
        cr[i1] = cr[i2] = true;
        i1 = p[i1], i2 = n[i2];
        if(i1 < 0 || i2 >= N) continue;
        p[i2] = i1;
        n[i1] = i2;
        if(d[i1].s == d[i2].s) continue;
        double val = ((double)(d[i1].f - d[i2].f)) / (d[i2].s - d[i1].s);
        if(val < 0) continue;
        pq.push({val, {i1, i2}});
    }
    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(!cr[i]) ans.push_back(i+1);
    }
    moo << ans.size() << endl;
    for(int i : ans) moo << i << " ";
    moo << endl;
}
