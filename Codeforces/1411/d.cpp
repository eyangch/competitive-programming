#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

string s;
int x, y, val, BIT[2][300000];
vector<int> q;

void upd(int id, int i, int v){
    for(; i <= (int)s.size(); i += i & -i){
        BIT[id][i] += v;
    }
}

int qry(int id, int i){
    int ret = 0;
    for(; i > 0; i -= i & -i){
        ret += BIT[id][i];
    }
    return ret;
}

int calc(int b){
    val = 0;
    fill_n(&BIT[0][0], 2*300000, 0);
    for(int i = 0; i < (int)s.size(); i++){
        int v = 0;
        if(s[i] == '?') v = b;
        else v = s[i] - '0';
        if(v){
            val += qry(0, i) * x;
        }else{
            val += qry(1, i) * y;
        }
        upd(v, i+1, 1);
    }
    int ans = val;
    for(int i : q){
        int z = qry(1, i) * y + (qry(1, s.size()) - qry(1, i+1)) * x;
        int o = qry(0, i) * x + (qry(0, s.size()) - qry(0, i+1)) * y;
        if(!b) val -= z;
        else val -= o;
        if(!b) val += o;
        else val += z;
        ans = min(ans, val);
        upd(b, i+1, -1);
        upd(!b, i+1, 1);
    }
    return ans;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> s >> x >> y;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '?') q.push_back(i);
    }
    moo << min(calc(0), calc(1)) << endl;
}
