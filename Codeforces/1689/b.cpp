#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, p[1000], a[1000];
bool used[1000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) eat >> p[i];
        if(N == 1){
            moo << -1 << endl;
            continue;
        }
        fill(used, used+N, 0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if((j+1 == p[i] && i != N-1) || used[j]) continue;
                a[i] = j+1;
                used[j] = true;
                break;
            }
        }
        if(a[N-1] == p[N-1]) swap(a[N-1], a[N-2]);
        for(int i = 0; i < N; i++) moo << a[i] << ' ';
        moo << endl;
    }
}
