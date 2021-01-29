#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M;
string s;
int id[128];
vector<char> ord;
int occ[20][20];
int dp[1<<20];

int dpf(int id){
    if(__builtin_popcount(id) == 1){
        int ret = 0;
        for(int i = 0; i < M; i++){
            if(id & (1<<i)){
                ret = occ[i][i];
            }
        }
        return ret;
    }
    if(~dp[id]) return dp[id];
    int ret = 1e9;
    for(int i = 0; i < M; i++){
        if(id & (1<<i)){
            int cost = 0;
            for(int j = 0; j < M; j++){
                if(!(id & (1<<j))) continue;
                cost += occ[i][j];
            }
            int nxt = dpf(id & ~(1<<i));
            ret = min(ret, nxt + cost);
        }
    }
    return dp[id] = ret;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    N = s.size();
    fill(id, id+128, -1);
    for(char i : s){
        if(~id[(int)i]) continue;
        id[(int)i] = ord.size();
        ord.push_back(i);
    }
    M = ord.size();
    for(int i = 1; i < N; i++){
        int id1 = id[(int)s[i-1]], id2 = id[(int)s[i]];
        occ[id1][id2]++;
    }
    fill(dp, dp+(1<<M), -1);
    cout << dpf((1<<M)-1)+1 << endl;
}
