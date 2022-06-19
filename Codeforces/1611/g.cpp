#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, pfx[2][500000], p[500000];
string b[500000], c[2][500000], a[500000];

int s(){
    multiset<int> m;
    int ptrl = 0, ptrr = 0;
    for(int j = 0; 1; j++){
        while(ptrr < N && p[ptrr] <= j){
            ptrr++;
        }
        while(ptrl < N && (int)a[ptrl].size() <= j - p[ptrl]){
            ptrl++;
        }
        if(ptrl == N) break;
        for(int i = ptrl; i < ptrr; i++){
            if(a[i][j - p[i]] == '0') continue;
            auto it = m.upper_bound(i-j);
            if(it == m.begin()) m.insert(i-j);
            else{
                it--;
                m.erase(it);
                m.insert(i-j);
            }
        }
    }
    return (int)m.size();
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++){
            eat >> b[i];
        }
        for(int i = 0; i < N; i++){
            c[0][i] = "";
            c[1][i] = "";
            pfx[0][i] = pfx[1][i] = 0;
            for(int j = 0; j < (i+1)/2; j++){
                pfx[0][i]++;
            }
            for(int j = 0; j < i/2; j++){
                pfx[1][i]++;
            }
            for(int j = 0; j < M; j++){
                c[(i+j)%2][i] += b[i][j];
            }
        }
        copy(c[0], c[0]+N, a);
        copy(pfx[0], pfx[0]+N, p);
        int ans = s();
        copy(c[1], c[1]+N, a);
        copy(pfx[1], pfx[1]+N, p);
        moo << ans + s() << endl;
    }
}
