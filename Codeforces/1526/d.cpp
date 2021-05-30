#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct BIT{
    int ar[300000], N;
    void init(int N){
        this->N = N;
        fill(ar, ar+N+1, 0);
    }
    void upd(int i, int dv){
        i++;
        for(; i <= N; i += i&-i) ar[i] += dv;
    }
    int qry(int i){
        i++;
        int ret = 0;
        for(; i > 0; i -= i&-i) ret += ar[i];
        return ret;
    }
};

int T, N;
string s;
char base[4] = {'A', 'N', 'T', 'O'};
int occ[4];
BIT *bit = new BIT();

int cvt(char c){
    if(c == 'A') return 0;
    if(c == 'N') return 1;
    if(c == 'T') return 2;
    if(c == 'O') return 3;
}

int test(string t){
    bit->init(N);
    int ret = 0;
    int ptr[4] = {0, 0, 0, 0};
    for(int i = 0; i < N; i++){
        int cur = cvt(s[i]);
        while(ptr[cur] < N && t[ptr[cur]] != s[i]){
            ptr[cur]++;
        }
        int idx = ptr[cur]++;
        int adjidx = idx + bit->qry(N-1) - bit->qry(idx);
        ret += adjidx - i;
        bit->upd(idx, 1);
    }
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> s;
        N = s.length();
        for(int c = 0; c < 4; c++){
            occ[c] = 0;
            for(int i = 0; i < N; i++){
                occ[c] += (s[i] == base[c]);
            }
        }
        int mxn = -1;
        string mxs;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    for(int l = 0; l < 4; l++){
                        if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
                        string cur = string(occ[i], base[i]) + string(occ[j], base[j]) + string(occ[k], base[k]) + string(occ[l], base[l]);
                        int num = test(cur);
                        if(num > mxn){
                            mxs = cur, mxn = num;
                        }
                    }
                }
            }
        }
        moo << mxs << endl;
    }
}
