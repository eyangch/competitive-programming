#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[100000];
map<int, int> occ[2];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        occ[0].clear(), occ[1].clear();
        for(int i = 0; i < N; i++){
            occ[i%2][a[i]]++;
        }
        sort(a, a+N);
        for(int i = 0; i < N; i++){
            occ[i%2][a[i]]--;
        }
        bool good = true;
        for(int i = 0; i < 2; i++){
            for(auto it = occ[i].begin(); it != occ[i].end(); it++){
                if(it -> second){
                    good = false;
                    break;
                }
            }
        }
        if(good) moo << "YES" << endl;
        else moo << "NO" << endl;
    }
}
