#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, rp[200], p[200];
bool vis[200];
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> s;
        for(int i = 0; i < N; i++){
            eat >> rp[i];
            rp[i]--;
        }
        for(int i = 0; i < N; i++){
            p[rp[i]] = i;
        }
        fill(vis, vis+N, 0);
        int ans = 1;
        for(int i = 0; i < N; i++){
            if(vis[i]) continue;
            string og = "";
            vector<int> ord;
            int v = i;
            do{
                ord.push_back(v);
                v = p[v];
                vis[v] = true;
            }while(v != i);
            for(int j : ord){
                og += s[j];
            }
            int rot = 0;
            while(true){
                rot++;
                bool good = true;
                for(int j = 0; j < (int)ord.size(); j++){
                    if(og[j] != og[(j+rot)%ord.size()]){
                        good = false;
                        break;
                    }
                }
                if(good) break;
            }
            ans = lcm(ans, rot);
        }
        moo << ans << endl;
    }
}
