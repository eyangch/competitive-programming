#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, xv[100000], ans;

int qry(string t, int i, int j){
    moo << t << ' ' << i+1 << ' ' << j+1 << endl;
    moo.flush();
    int ret; eat >> ret;
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    int multi = -1;
    set<int> prev;
    prev.insert(0), xv[0] = 0;
    for(int i = 1; i < N; i++){
        xv[i] = qry("XOR", i, 0);
        if(prev.count(xv[i])) multi = xv[i];
        prev.insert(xv[i]);
    }
    if(~multi){
        vector<int> l;
        for(int i = 0; i < N; i++){
            if(xv[i] == multi) l.push_back(i);
        }
        int v = qry("AND", l[0], l[1]);
        ans = v ^ xv[l[0]];
    }else{
        int l1 = (xv[1] == N-1 ? 2 : 1), l2 = 0;
        for(int i = 1; i < N; i++){
            if((xv[l1] ^ xv[i]) == N-1) l2 = i;
        }
        int x1 = xv[0] ^ xv[l1], x2 = xv[0] ^ xv[l2], x3 = xv[l1] ^ xv[l2];
        int a1 = qry("AND", 0, l1), a2 = qry("AND", 0, l2);
        ans = (x1 + 2 * a1 + x2 + 2 * a2 - x3) / 2;
    }
    moo << "! " << ans;
    for(int i = 1; i < N; i++){
        moo << ' ' << (ans ^ xv[i]);
    }
    moo << endl;
}
