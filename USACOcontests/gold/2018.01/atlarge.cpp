#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    int N, K; cin >> N >> K;
    K--;
    vi graph[N];
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);   
    }
    ll depth[N];
    vi revdepth[N];
    fill(depth, depth + N, -1);
    stack<pii> dfs_depth;
    dfs_depth.push(pii(K, 0));
    while(!dfs_depth.empty()){
        pii idx = dfs_depth.top();
        dfs_depth.pop();
        if(depth[idx.first] != -1){
            continue;
        }
        depth[idx.first] = idx.second;
        revdepth[idx.second].push_back(idx.first);
        for(int i : graph[idx.first]){
            dfs_depth.push(pii(i, idx.second + 1));
        }
    }
    int leaf_depth[N];
    for(int i = N-1; i >= 0; i--){
        for(int j : revdepth[i]){
            vi children;
            for(int k : graph[j]){
                if(depth[k] > i){
                    children.push_back(k);
                }
            }
            if((int)children.size() == 0){
                leaf_depth[j] = 0;
            }else{
                leaf_depth[j] = leaf_depth[children[0]]+1;
                for(int k = 1; k < (int)children.size(); k++){
                    leaf_depth[j] = min(leaf_depth[j], leaf_depth[children[k]]+1);
                }
            }
        }
    }
    if(leaf_depth[K] == 0){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    queue<int> bfs;
    bfs.push(K);
    bool been[N];
    fill(been, been+N, false);
    while(!bfs.empty()){
        int idx = bfs.front();
        bfs.pop();
        if(been[idx]) continue;
        been[idx] = true;
        if(depth[idx] == leaf_depth[idx] || depth[idx] == leaf_depth[idx] + 1){
            ans++;
            continue;
        }
        for(int i : graph[idx]){
            bfs.push(i);
        }
    }
    cout << ans << endl;
    return 0;
}


