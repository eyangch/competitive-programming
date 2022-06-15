#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[200000], nxt[200000];
bool vis[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        map<int, int> prev;
        fill(nxt, nxt+N, -1);
        fill(vis, vis+N, 0);
        for(int i = 0; i < N; i++){
            eat >> a[i];
            if(prev.count(a[i])){
                nxt[prev[a[i]]] = i;
            }
            prev[a[i]] = i;
        }
        int mx = 0;
        int ma = 0;
        int ml = 0;
        int mr = 0;
        for(int i = 0; i < N; i++){
            if(vis[i]) continue;
            int p = i;
            int cur = 1;
            int cl = i;
            while(true){
                vis[p] = true;
                if(cur < 1) cur = 1, cl = p;
                if(cur >= mx){
                    mx = cur;
                    ma = a[i];
                    ml = cl;
                    mr = p;
                }
                cur += 2;
                cur -= nxt[p] - p;
                if(nxt[p] == -1) break;
                p = nxt[p];
            }
        }
        moo << ma << ' ' << ml + 1 << ' ' << mr + 1 << endl;
    }
}
