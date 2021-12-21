#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

struct segt{
    int a[400001][1<<5]; // a, b, c, ab, bc
    int N;
    string s[5] = {"a", "b", "c", "ab", "bc"};
    vector<pair<int, int>> tf[1<<5], f[1<<5];
    void init(int N){
        this->N = N;
        for(int i = 1; i < 1<<5; i++){
            if(i & (1<<4) && !(i & (1<<1) || i & (1<<2))) continue;
            if(i & (1<<5) && !(i & (1<<3) || i & (1<<2))) continue;
            for(int j = 1; j < 1<<5; j++){
                if(j & (1<<4) && !(j & (1<<1) || j & (1<<2))) continue;
                if(j & (1<<5) && !(j & (1<<3) || j & (1<<2))) continue;
                int targ = 0;
                for(int k = 0; k < 5; k++){
                    if(!(i & (1<<k))) continue;
                    for(int l = 0; l < 5; l++){
                        if(!(j & (1<<l))) continue;
                        string cur = s[k] + s[l];
                        if(cur.find("abc") != -1) targ = -1;
                        for(int m = 0; m < 5; m++){
                            if(cur.find(s[m]) != -1) targ |= (1<<m);
                        }
                    }
                }
                if(targ < 0) continue;
                tf[targ].push_back({i, j});
            }
        }
        for(int i = 0; i < 1<<5; i++){
            for(pair<int, int> j : tf[i]){
                bool b1 = (j.fi == 1 || j.fi == 2 || j.fi == 4);
                bool b2 = (j.se == 1 || j.se == 2 || j.se == 4);
                b1 |= ((int)tf[j.fi].size() > 0);
                b2 |= ((int)tf[j.se].size() > 0);
                if(b1 && b2) f[i].push_back(j);
            }
        }
    }
    void upd(int i, char v, int l=0, int r=-1, int x=1){
        if(r == -1) r = N-1;
        if(i > r || i < l) return;
        if(l == r){
            for(int j = 0; j < 1<<5; j++){
                a[x][j] = 1e15;
            }
            if(v == 'a'){
                a[x][0b00001] = 0;
                a[x][0b00010] = a[x][0b00100] = 1;
            }if(v == 'b'){
                a[x][0b00010] = 0;
                a[x][0b00001] = a[x][0b00100] = 1;
            }if(v == 'c'){
                a[x][0b00100] = 0;
                a[x][0b00001] = a[x][0b00010] = 1;
            }
            return;
        }
        upd(i, v, l, (l+r)/2, x*2);
        upd(i, v, (l+r)/2+1, r, x*2+1);
        for(int j = 1; j < 1<<5; j++){
            a[x][j] = 1e15;
            for(pair<int, int> p : f[j]){
                a[x][j] = min(a[x][j], a[x*2][p.fi] + a[x*2+1][p.se]);
            }
        }
    }
    int qry(){
        int ans = 1e15;
        for(int i = 1; i < 1<<5; i++){
            ans = min(ans, a[1][i]);
        }
        return ans;
    }
};

int N, Q;
segt s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Q;
    s.init(N);
    string st; eat >> st;
    for(int i = 0; i < N; i++){
        s.upd(i, st[i]);
    }
    while(Q--){
        int i;
        char c;
        eat >> i >> c;
        s.upd(i-1, c);
        moo << s.qry() << endl;
    }
}
