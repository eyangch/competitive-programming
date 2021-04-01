#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct vec_hash{
    size_t operator()(std::vector<int> const &vec) const{
        size_t seed = vec.size();
        for(auto &i : vec){
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

int T, N, M;
long long rt = 0, sum = 0;
unordered_set<vector<int>, vec_hash> ans;
vector<int> cur;
long long targ = (1e9+7);
int ops = 0;
int maxops = 700000;
int tamt = 2000;

void dfs(int id){
    if(rt <= targ){
        if(rt == targ) ans.insert(cur);
        return;
    }
    ops++;
    if(ops > maxops || (int)ans.size() == tamt) return;
    for(int i = id; i < N; i++){
        if(cur[i] == 1 || (i > 0 && cur[i]-1 < cur[i-1])) continue;
        rt -= (sum - cur[i]), cur[i]--, sum--;
        dfs(i);
        if(ops > maxops || (int)ans.size() == tamt) return;
        sum++, cur[i]++, rt += (sum - cur[i]);
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T >> N >> M;
    N = 46;
    for(int div = 8; div > 0; div--){
        for(M = 1000; true; M--){
            ops = 0;
            sum = 0;
            rt = 0;
            cur.clear();
            for(int i = 0; i < N; i++) cur.push_back(1000);
            for(int i = 0; i < N * div / 8; i++) cur[i] = M;
            for(int i = 0; i < N; i++){
                sum += cur[i];
            }
            int xsum = sum;
            for(int i = 0; i < N; i++){
                xsum -= cur[i];
                rt += xsum * cur[i];
            }
            if(rt < targ) break;
            dfs(0);
            if((int)ans.size() >= tamt) break;
        }
        if((int)ans.size() >= tamt) break;
    }
    moo << ans.size() << endl;
    for(vector<int> v : ans){
        moo << v.size() << endl;
        for(int i : v) moo << i << " ";
        moo << endl;
    }
}
