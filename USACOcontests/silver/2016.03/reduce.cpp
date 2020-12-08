#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int N;
pii c[50000];
int sx[50000], sy[50000];
set<pii> xset, yset;

bool srtx(int a, int b){
    return c[a].f < c[b].f;
}

bool srty(int a, int b){
    return c[a].s < c[b].s;
}

int dfs(int rm){
    if(rm == 3){
        pii mn_x = *xset.begin();
        pii mx_x = *xset.rbegin();
        pii mn_y = *yset.begin();
        pii mx_y = *yset.rbegin();
        return (mx_x.f-mn_x.f) * (mx_y.f-mn_y.f);
    }
    int ret = 2e9;
    int add = 0;
    for(int i = 0; i < 3; i++){
        while(!xset.count(pii(c[sx[i+add]].f, sx[i+add]))){
            add++;
        }
        xset.erase(pii(c[sx[i+add]].f, sx[i+add]));
        yset.erase(pii(c[sx[i+add]].s, sx[i+add]));
        ret = min(ret, dfs(rm+1));
        xset.insert(pii(c[sx[i+add]].f, sx[i+add]));
        yset.insert(pii(c[sx[i+add]].s, sx[i+add]));
    }
    add = 0;
    for(int i = 0; i < 3; i++){
        while(!xset.count(pii(c[sx[N-1-i-add]].f, sx[N-1-i-add]))){
            add++;
        }
        xset.erase(pii(c[sx[N-1-i-add]].f, sx[N-1-i-add]));
        yset.erase(pii(c[sx[N-1-i-add]].s, sx[N-1-i-add]));
        ret = min(ret, dfs(rm+1));
        xset.insert(pii(c[sx[N-1-i-add]].f, sx[N-1-i-add]));
        yset.insert(pii(c[sx[N-1-i-add]].s, sx[N-1-i-add]));
    }
    add = 0;
    for(int i = 0; i < 3; i++){
        while(!yset.count(pii(c[sy[i+add]].s, sy[i+add]))){
            add++;
        }
        xset.erase(pii(c[sy[i+add]].f, sy[i+add]));
        yset.erase(pii(c[sy[i+add]].s, sy[i+add]));
        ret = min(ret, dfs(rm+1));
        xset.insert(pii(c[sy[i+add]].f, sy[i+add]));
        yset.insert(pii(c[sy[i+add]].s, sy[i+add]));
    }
    add = 0;
    for(int i = 0; i < 3; i++){
        while(!yset.count(pii(c[sy[N-1-i-add]].s, sy[N-1-i-add]))){
            add++;
        }
        xset.erase(pii(c[sy[N-1-i-add]].f, sy[N-1-i-add]));
        yset.erase(pii(c[sy[N-1-i-add]].s, sy[N-1-i-add]));
        ret = min(ret, dfs(rm+1));
        xset.insert(pii(c[sy[N-1-i-add]].f, sy[N-1-i-add]));
        yset.insert(pii(c[sy[N-1-i-add]].s, sy[N-1-i-add]));
    }
    return ret;
}

signed main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c[i].f >> c[i].s;
        xset.insert(pii(c[i].f, i));
        yset.insert(pii(c[i].s, i));
    }
    iota(sx, sx+N, 0);
    iota(sy, sy+N, 0);
    sort(sx, sx+N, srtx);
    sort(sy, sy+N, srty);
    cout << dfs(0) << endl;
    return 0;
}


