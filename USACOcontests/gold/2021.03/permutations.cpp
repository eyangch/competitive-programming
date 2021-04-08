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

double sidel(pii a, pii b){
    return sqrt((a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));
}

double heron(pii a, pii b, pii c){
    double sa = sidel(a, b), sb = sidel(b, c), sc = sidel(c, a);
    double s = (sa + sb + sc) / 2.0;
    double area = sqrt(s * (s - sa) * (s - sb) * (s - sc));
    return area;
}

bool in_tri(pii p, pii a, pii b, pii c){
    double area = heron(a, b, c);
    double area1 = heron(p, a, b);
    double area2 = heron(p, b, c);
    double area3 = heron(p, c, a);
    return (abs(area - area1 - area2 - area3) < 0.001);
}

struct tri{
    int p, i1, i2, i3;
};
struct c_tri{
    bool operator()(const tri &a, const tri &b){
        return a.p > b.p;
    }
};

int perm[40], dp[40][40][40], ct[40][40][40];
pii pt[40];
int MOD = 1e9+7;

int v_tri(int i, int p0, int p1, int p2){
    if(in_tri(pt[p0], pt[i], pt[p1], pt[p2])){
        return 0;
    }
    if(in_tri(pt[p1], pt[p0], pt[i], pt[p2])){
        return 1;
    }
    if(in_tri(pt[p2], pt[p0], pt[p1], pt[i])){
        return 2;
    }
    return -1;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> pt[i].f >> pt[i].s;
    }
    iota(perm, perm+N, 0);
    int ans = 0;
    priority_queue<tri, vector<tri>, c_tri> pq;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                int cnt = 0;
                for(int l = 0; l < N; l++){
                    if(l == i || l == j || l == k) continue;
                    if(in_tri(pt[l], pt[i], pt[j], pt[k])){
                        cnt++;
                    }
                }
                pq.push({cnt, i, j, k});
                ct[i][j][k] = cnt;
            }
        }
    }
    while(!pq.empty()){
        tri t = pq.top();
        pq.pop();
        int cnt = t.p, i1 = t.i1, i2 = t.i2, i3 = t.i3;
        int xtra1 = ct[i1][i2][i3];
        int left1 = N - ct[i1][i2][i3] - 3 + 1;
        int mul1 = 1;
        for(int j = 0; j < xtra1; j++) mul1 = mul1 * (left1 + j) % MOD;
        dp[i1][i2][i3] += 6 * mul1;
        dp[i1][i2][i3] %= MOD;
        for(int i = 0; i < N; i++){
            if(i == i1 || i == i2 || i == i3) continue;
            if(in_tri(pt[i], pt[i1], pt[i2], pt[i3])) continue;
            int x = v_tri(i, i1, i2, i3);
            int t1 = i1, t2 = i2, t3 = i3;
            if(x == 0) t1 = i;
            else if(x == 1) t2 = i;
            else if(x == 2) t3 = i;
            else continue;
            if(t1 > t2) swap(t1, t2);
            if(t1 > t3) swap(t1, t3);
            if(t2 > t3) swap(t2, t3);
            int xtra = ct[t1][t2][t3] - ct[i1][i2][i3] - 1;
            int left = N - ct[t1][t2][t3] - 3 + 1;
            int mul = 1;
            for(int j = 0; j < xtra; j++) mul = mul * (left + j) % MOD;
            dp[t1][t2][t3] += dp[i1][i2][i3] * (mul);
            dp[t1][t2][t3] %= MOD;
        }
    }
    int x1, x2, x3;
    bool bad = true;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                bool cur = false;
                for(int l = 0; l < N; l++){
                    if(l == i || l == j || l == k) continue;
                    if(!in_tri(pt[l], pt[i], pt[j], pt[k])){
                        cur = true;
                    }
                }
                if(!cur){
                    x1 = i, x2 = j, x3 = k;
                }
                bad &= cur;
            }
        }
    }
    moo << (bad ? 0 : dp[x1][x2][x3]) << endl;
}
