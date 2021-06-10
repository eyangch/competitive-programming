#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;

struct dat{
    int num, l, r, len;
    string s;
};

pair<int, int> lrf(string val){
    pair<int, int> cur = {0, 0};
    if(val[0] == 'a') cur.f = 1;
    if(val.size() >= 2 && val.substr(0, 2) == "ha") cur.f = 2;
    if(val.size() >= 3 && val.substr(0, 3) == "aha") cur.f = 3;
    if(val[val.size()-1] == 'h') cur.s = 1;
    if(val.size() >= 2 && val.substr(val.size() - 2, 2) == "ha") cur.s = 2;
    if(val.size() >= 3 && val.substr(val.size() - 3, 3) == "hah") cur.s = 3;
    return cur;
}

int T, N;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        map<string, dat> m;
        string lst = "";
        for(int i = 0; i < N; i++){
            string var, op; eat >> var >> op;
            lst = var;
            if(op == ":="){
                string val; eat >> val;
                dat cur = {0, 0, 0, val.size(), val};
                if(val.size() >= 4 && (val.substr(0, 4) == "haha" || val.substr(1, 4) == "haha")){
                    cur.num = 1;
                }
                pair<int, int> lrv = lrf(val);
                cur.l = lrv.f, cur.r = lrv.s;
                m[var] = cur;
            }else{
                string v1, plus, v2; eat >> v1 >> plus >> v2;
                dat d1 = m[v1], d2 = m[v2];
                dat cur = {0, d1.l, d2.r, d1.len + d2.len, ""};
                if(cur.len < 10){
                    cur.s = d1.s + d2.s;
                }
                cur.num = d1.num + d2.num;
                if(d1.r + d2.l == 4){
                    cur.num++;
                }
                if(d1.r == 3 && d2.l == 3) cur.num += 2;
                if(cur.len < 10){
                    pair<int, int> lrv = lrf(cur.s);
                    cur.l = lrv.f, cur.r = lrv.s;
                }
                m[var] = cur;
            }
        }
        moo << m[lst].num << endl;
    }
}
