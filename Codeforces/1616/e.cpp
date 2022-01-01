#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

struct BIT{
    int N, BIT[100001];
    void init(int N){
        this->N = N;
        fill(BIT, BIT+N+1, 0);
    }
    void upd(int i, int x){
        if(i > N) return;
        for(i++; i <= N; i += i & -i){
            BIT[i] += x;
        }
    }
    int qry(int i, int sum=0){
        if(i > N) return 0;
        for(i++; i > 0; i -= i & -i){
            sum += BIT[i];
        }
        return sum;
    }
} BIT;

int Q, N, nxt[100000], B[26], P[26];
string S, T;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> Q;
    while(Q--){
        eat >> N >> S >> T;
        fill(nxt, nxt+N, 1e16);
        fill(B, B+26, 1e16);
        fill(P, P+26, 1e16);
        for(int i = 0; i < N; i++){
            int c = S[i]-'a';
            if(P[c] == 1e16){
                P[c] = i;
                B[c] = i;
            }else{
                nxt[P[c]] = i;
                P[c] = i;
            }
        }
        BIT.init(N);
        int ans = 1e16, ccost = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < T[i]-'a'; j++){
                ans = min(ans, ccost + B[j] + BIT.qry(B[j]));
            }
            if(B[T[i]-'a'] > N) break;
            ccost += B[T[i]-'a'] + BIT.qry(B[T[i]-'a']);
            BIT.upd(B[T[i]-'a'], -1);
            B[T[i]-'a'] = nxt[B[T[i]-'a']];
        }
        moo << (ans < 1e14 ? ans : -1) << endl;
    }
}
