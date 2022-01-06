#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int N, Q, S, P[100000], R[100000], J[100000];

void upd(int x){
    J[x] = x;
    for(int j = 0; j < S; j++){
        J[x] = P[J[x]];
    }
    int cur1 = x, cur2 = J[x];
    for(int j = 0; j < S; j++){
        cur1 = R[cur1];
        cur2 = R[cur2];
        J[cur1] = cur2;
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Q;
    S = sqrt(N);
    for(int i = 0; i < N; i++){
        eat >> P[i];
        P[i]--;
    }
    for(int i = 0; i < N; i++){
        R[P[i]] = i;
    }
    for(int i = 0; i < N; i++){
        J[i] = i;
        for(int j = 0; j < S; j++) J[i] = P[J[i]];
    }
    for(int i = 0; i < Q; i++){
        int t; eat >> t;
        if(t == 1){
            int x, y; eat >> x >> y;
            x--, y--;
            swap(P[x], P[y]);
            swap(R[P[x]], R[P[y]]);
            upd(x), upd(y);
        }else{
            int id, k; eat >> id >> k;
            id--;
            for(int j = 0; j < k/S; j++){
                id = J[id];
            }
            for(int j = 0; j < k%S; j++){
                id = P[id];
            }
            moo << id + 1 << endl;
        }
    }
}
