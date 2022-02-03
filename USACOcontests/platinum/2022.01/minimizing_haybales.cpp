#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

struct segt{
    int N, v[500000], lazy[500000], l[500000], r[500000];
    void init(int il, int ir, int i=1){
        l[i] = il, r[i] = ir;
        if(l[i] == r[i]) return;
        init(il, (il+ir)/2, i*2);
        init((il+ir)/2+1, ir, i*2+1);
    }
    void push(int i){
        if(l[i] != r[i]){
            v[i*2] += lazy[i];
            v[i*2+1] += lazy[i];
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    void upd(int ul, int ur, int uv, int i=1){
        if(ul > ur) return;
        if(l[i] > ur || r[i] < ul) return;
        push(i);
        if(l[i] >= ul && r[i] <= ur){
            lazy[i] += uv;
            v[i] += uv;
            push(i);
        }else{
            push(i);
            upd(ul, ur, uv, i*2);
            upd(ul, ur, uv, i*2+1);
            v[i] = min(v[i*2], v[i*2+1]);
        }
    }
    int nxtz(int ul, int ur, int i=1){
        if(ul > ur) return -1;
        if(l[i] > ur || r[i] < ul) return -1;
        push(i);
        if(v[i] > 0) return -1;
        if(l[i] == r[i]) return l[i];
        int a = nxtz(ul, ur, i*2);
        if(a != -1) return a;
        return nxtz(ul, ur, i*2+1);
    }
    int qry(int x, int i=1){
        if(r[i] < x || l[i] > x) return 1e16;
        push(i);
        if(l[i] == r[i]) return v[i];
        return min(qry(x, i*2), qry(x, i*2+1));
    }
} S;

int N, K, A[100000], sA[100000], C[100000], cc[100000], L[100000], R[100000];

bool d(int a, int b){
    return (a - b > K || b - a > K);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K;
    S.init(0, N-1);
    for(int i = 0; i < N; i++) eat >> A[i];
    copy(A, A+N, sA);
    sort(sA, sA+N);
    iota(C, C+N, 0);
    sort(C, C+N, [](int a, int b){
        return A[a] < A[b];
    });
    for(int i = 0; i < N; i++){
        cc[C[i]] = i;
    }
    int pL = 0, pR = 0; // INCLUSIVE L + R
    for(int i = 0; i < N; i++){
        while(pL < N && sA[pL] < sA[i] - K){
            pL++;
        }
        while(pR < N && sA[pR] <= sA[i] + K){
            pR++;
        }
        L[i] = pL, R[i] = pR-1;
    }
    for(int i = N-1; i >= 0; i--){
        int id = cc[i];
        int curv = S.qry(id);
        S.upd(id, id, -curv);
        S.upd(0, L[id]-1, 1);
        S.upd(R[id]+1, N-1, 1);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < N; i++){
        if(S.qry(cc[i]) == 0){
            pq.push({A[i], i});
            S.upd(cc[i], cc[i], 1e16);
        }
    }
    while(!pq.empty()){
        int v = pq.top().fi;
        int id = pq.top().se;
        int cid = cc[id];
        pq.pop();
        moo << v << endl;
        S.upd(0, L[cid]-1, -1);
        int nxtz = -1;
        while((nxtz = S.nxtz(0, L[cid]-1)) != -1){
            S.upd(nxtz, nxtz, 1e16);
            pq.push({sA[nxtz], C[nxtz]});
        }
        S.upd(R[cid]+1, N-1, -1);
        nxtz = -1;
        while((nxtz = S.nxtz(R[cid]+1, N-1)) != -1){
            S.upd(nxtz, nxtz, 1e16);
            pq.push({sA[nxtz], C[nxtz]});
        }
    }
}
