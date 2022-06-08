#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, a[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        set<int> active;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        reverse(a, a+N);
        for(int i = 0; i < N; i++){
            auto it = active.insert(i).first;
            while(it != active.begin()){
                it--;
                if(a[*it] < a[i]) break;
                it = active.erase(it);
                if(it == active.begin()) break;
            }
        }
        for(int i = 0; i < M; i++){
            int k, d; eat >> k >> d;
            k = N-k;
            a[k] -= d;
            auto nx = active.upper_bound(k);
            if(nx != active.end()){
                if(a[*nx] <= a[k]){
                    moo << active.size() << ' ';
                    continue;
                }
            }
            auto it = active.insert(k).first;
            while(it != active.begin()){
                it--;
                if(a[*it] < a[k]) break;
                it = active.erase(it);
            }
            moo << active.size() << ' ';
        }
        moo << endl;
    }
}
