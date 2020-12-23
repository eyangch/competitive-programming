#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct pair_hash{
    inline size_t operator ()(pair<pair<int, int>, pair<int, int>> const &pair) const{
        size_t h11 = hash<int>()(pair.first.first);
        size_t h12 = hash<int>()(pair.first.second);
        size_t h21 = hash<int>()(pair.second.first);
        size_t h22 = hash<int>()(pair.second.second);
        return h11 ^ h12 ^ h21 ^ h22;
    }
};

int N;
vector<int> dv;
vector<int> pv;
set<int> ans;
gp_hash_table<pair<pair<int, int>, pair<int, int>>, null_type, pair_hash> vis;

void dfs(int id){
    int sum = 0, mp = 1, sum2 = pv.size();
    for(int i : pv){
        sum += i-1;
        mp *= i-1;
    }
    if(vis.find({{sum, mp}, {id, sum2}}) != vis.end()) return;
    vis.insert({{sum, mp}, {id, sum2}});
    if(id == (int)dv.size()){
        ans.insert(sum);
        return;
    }
    pv.push_back(dv[id]);
    dfs(id+1);
    pv.pop_back();
    for(int i = 0; i < (int)pv.size(); i++){
        pv[i] *= dv[id];
        dfs(id+1);
        pv[i] /= dv[id];
    }
}

signed main(){
    cin >> N;
    for(int i = 2; i * i <= N; i++){
        while(N % i == 0){
            N /= i;
            dv.push_back(i);
        }
    }
    if(N > 1){
        dv.push_back(N);
    }
    dfs(0);
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
}
