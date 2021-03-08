#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define f first
#define s second
#define int long long

using namespace std;

struct line{int a, b, c;};

bool line_sf(line x, line y){
    return x.a < y.a;
}

int N, BIT[30000];
vector<line> v, h;

void upd(int i, int x){
    for(; i <= 15000; i += i & -i){
        BIT[i] += x;
    }
}

int qry(int i){
    int ret = 0;
    for(; i > 0; i -= i & -i){
        ret += BIT[i];
    }
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        int x1, y1, x2, y2; eat >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        x1 += 5001, x2 += 5001, y1 += 5001, y2 += 5001;
        if(x1 == x2){
            v.push_back({x1, y1, y2});
        }else{
            h.push_back({y1, x1, x2});
        }
    }
    sort(v.begin(), v.end(), line_sf);
    sort(h.begin(), h.end(), line_sf);
    int ans = 0;
    for(int i = 0; i < (int)v.size(); i++){
        multiset<pair<int, int>, greater<pair<int, int>>> active;
        fill_n(BIT, 30000, 0);
        for(int j = 0; j < (int)h.size(); j++){
            if(h[j].b <= v[i].a){
                active.insert({h[j].c, h[j].a});
            }
        }
        for(int j = (int)v.size() - 1; j > i; j--){
            while(active.size() && active.begin()->first >= v[j].a){
                upd(active.begin()->second, 1);
                active.erase(active.begin());
            }
            int lo = max(v[i].b, v[j].b), hi = min(v[i].c, v[j].c);
            int segs = max(0LL, qry(hi) - qry(lo-1));
            ans += (segs-1) * segs / 2;
        }
    }
    moo << ans << endl;
}
