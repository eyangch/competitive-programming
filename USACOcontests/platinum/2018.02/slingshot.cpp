#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define f first
#define s second

using namespace std;
typedef pair<int, int> pii;

struct segt{
    long long v[800000];
    int vl[800000], vr[800000];
    void init(int l, int r, int i){
        v[i] = 1e17, vl[i] = l, vr[i] = r;
        int m = (l+r)/2;
        if(vl[i] >= vr[i]) return;
        init(l, m, i*2);
        init(m+1, r, i*2+1);
    }
    long long qry(int l, int r, int i){
        if(l > vr[i] || r < vl[i]){
            return 1e17;
        }
        if(l <= vl[i] && r >= vr[i]){
            return v[i];
        }
        return min(qry(l, r, i*2), qry(l, r, i*2+1));
    }
    void upd(int x, int i, long long d){
        //moo << x << " " << i << " " << d << " " << vl[i] << " " << vr[i] << endl;
        if(vl[i] > x || vr[i] < x) return;
        if(vl[i] == vr[i]){
            if(d == 1e17) v[i] = 1e17;
            else v[i] = min(v[i], d);
        }else{
            upd(x, i*2, d);
            upd(x, i*2+1, d);
            v[i] = min(v[i*2], v[i*2+1]);
        }
    }
};

struct ps{
    int a, b, c;
};

int N, M;
ps s[100000];
ps p[100000];
unordered_map<int, int> cy;
segt s1, s2, s3, s4;
long long ans[100000];

int32_t main(){
    freopen("slingshot.in", "r", stdin); freopen("slingshot.out", "w", stdout);
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    s1.init(0, N+M, 1), s2.init(0, N+M, 1), s3.init(0, N+M, 1), s4.init(0, N+M, 1);
    set<int> yv;
    for(int i = 0; i < N; i++){
        eat >> s[i].a >> s[i].b >> s[i].c;
        yv.insert(s[i].b);
    }
    for(int i = 0; i < M; i++){
        eat >> p[i].a >> p[i].b;
        p[i].c = i;
        yv.insert(p[i].b);
    }
    for(int i : yv){
        cy[i] = cy.size();
    }
    sort(s, s+N, [](ps a, ps b){return a.a < b.a;});
    sort(p, p+M, [](ps a, ps b){return a.a < b.a;});
    for(int i = 0; i < N; i++){
        int id = cy[s[i].b];
        long long sum = s[i].c + s[i].a + s[i].b;
        s3.upd(id, 1, sum);
        sum = s[i].c + s[i].a - s[i].b;
        s4.upd(id, 1, sum);
    }
    int p1 = 0, p2 = 0;
    int mxn = 0;
    for(int i = 0; i < M; i++){
        while(p1 < N && s[p1].a <= p[i].a){
            int id = cy[s[p1].b];
            long long sum = s[p1].c - s[p1].a + s[p1].b;
            s1.upd(id, 1, sum);
            if(sum < 0) mxn = max(mxn, id);
            sum = s[p1].c - s[p1].a - s[p1].b;
            s2.upd(id, 1, sum);
            p1++;
        }
        while(p2 < N && s[p2].a < p[i].a){
            int id = cy[s[p2].b];
            s3.upd(id, 1, 1e17);
            s4.upd(id, 1, 1e17);
            p2++;
        }
        long long i1 = s1.qry(cy[p[i].b], cy.size(), 1) + p[i].a - p[i].b;
        long long i2 = s2.qry(0, cy[p[i].b], 1) + p[i].a + p[i].b;
        long long i3 = s3.qry(cy[p[i].b], cy.size(), 1) - p[i].a - p[i].b;
        long long i4 = s4.qry(0, cy[p[i].b], 1) - p[i].a + p[i].b;
        ans[p[i].c] = min({(long long)abs(p[i].b - p[i].a), i1, i2, i3, i4});
    }
    s3.init(0, cy.size(), 1);
    s4.init(0, cy.size(), 1);
    p1 = M-1;
    for(int i = M-1; i >= 0; i--){
        while(p1 >= 0 && s[p1].a >= p[i].a){
            int id = cy[s[p1].b];
            long long sum = s[p1].c + s[p1].a + s[p1].b;
            s3.upd(id, 1, sum);
            if(sum < 0) mxn = max(mxn, id);
            sum = s[p1].c + s[p1].a - s[p1].b;
            s4.upd(id, 1, sum);
            p1--;
        }
        /*while(p2 < N && s[p2].a < p[i].a){
            int id = cy[s[p2].b];
            s3.upd(id, 1, 1e17);
            s4.upd(id, 1, 1e17);
            p2++;
        }*/
        long long i1 = s3.qry(cy[p[i].b], cy.size(), 1) - p[i].a - p[i].b;
        long long i2 = s4.qry(0, cy[p[i].b], 1) - p[i].a + p[i].b;
        //int i3 = s3.qry(cy[p[i].b], 200000, 1) - p[i].a - p[i].b;
        //int i4 = s4.qry(0, cy[p[i].b], 1) - p[i].a + p[i].b;
        ans[p[i].c] = min({ans[p[i].c], (long long)abs(p[i].b - p[i].a), i1, i2});
    }
    for(int i = 0; i < M; i++){
        moo << ans[i] << endl;
    }
}
