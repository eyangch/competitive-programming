#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[50000], b[50000], d[50000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) eat >> a[i];
        for(int i = 0; i < N; i++) eat >> b[i];
        for(int i = 0; i < N; i++){
            d[i] = a[i] - b[i];
        }
        bool good = true;
        int est = 2e9;
        for(int i = 0; i < N; i++){
            if(d[i] < 0){
                good = false;
                break;
            }
            if(b[i] == 0) continue;
            if(est == 2e9){
                est = d[i];
            }
            if(est != d[i]){
                good = false;
                break;
            }
        }
        for(int i = 0; i < N; i++){
            if(b[i] == 0){
                if(d[i] > est) good = false;
            }
        }
        moo << (good ? "YeS" : "no") << endl;
    }
}
