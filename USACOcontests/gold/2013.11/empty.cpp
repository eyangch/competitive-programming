#include <bits/stdc++.h>

using namespace std;

int N, K;
int c[3000000];
int q = 0;

signed main(){
    freopen("empty.in", "r", stdin);
    freopen("empty.out", "w", stdout);
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        long long X, Y, A, B; cin >> X >> Y >> A >> B;
        for(int j = 1; j <= Y; j++){
            c[(A*j+B)%N] += X;
        }
    }
    for(int i = 0; i < N; i++){
        q += c[i];
        c[i] = 0;
        if(q){
            c[i] = 1;
            q--;
        }
    }
    for(int i = 0; i < N; i++){
        if(!q && !c[i]){
            cout << i << endl;
            break;
        }
        if(!c[i]){
            q--;
        }
    }
}
