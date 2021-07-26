#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K, id[100], ans1[100], ans2[100];
vector<int> c[100];
bool used[100];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K;
    for(int i = 0; i < N * K; i++){
        int x; eat >> x;
        c[x-1].push_back(i);
    }
    iota(id, id+N, 0);
    for(int i = 1; i < K; i++){
        sort(id, id+N, [i](int x, int y){
            if(used[x]) return false;
            if(used[y]) return true;
            return (c[x][i] < c[y][i]);
        });
        for(int j = 0; j < (N / (K-1) + (N % (K-1) > 0)); j++){
            if(used[id[j]]) break;
            used[id[j]] = true;
            ans1[id[j]] = c[id[j]][i-1] + 1, ans2[id[j]] = c[id[j]][i] + 1;
        }
    }
    for(int i = 0; i < N; i++){
        moo << ans1[i] << ' ' << ans2[i] << endl;
    }
}
