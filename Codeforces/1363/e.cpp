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

int N;
int nodes[200000][3]; // cost, initial digit, goal digit
vi graph[200000];
int costs[200000];
int depth[200000];
vi revdepth[200000];
int zo[200000], oz[200000];

void dfs_costs(int idx, int mnum){
    if(costs[idx] != -1){
        return;
    }
    mnum = min(mnum, nodes[idx][0]);
    costs[idx] = mnum;
    for(int i : graph[idx]){
        dfs_costs(i, mnum);
    }
}

void dfs_depth(int node, int d){
    if(depth[node] != -1){
        return;
    }
    depth[node] = d;
    revdepth[d].push_back(node);
    for(int i : graph[node]){
        dfs_depth(i, d+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> nodes[i][0] >> nodes[i][1] >> nodes[i][2];   
    }
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    fill(costs, costs+N, -1);
    dfs_costs(0, INT_MAX);
    fill(depth, depth+N, -1);
    dfs_depth(0, 0);
    ll ans = 0;
    for(int i = N-1; i >= 0; i--){
        if(revdepth[i].size() == 0){
            continue;
        }
        for(int j : revdepth[i]){
            vi children;
            oz[j] = (nodes[j][1] == 1 && nodes[j][2] == 0);
            zo[j] = (nodes[j][1] == 0 && nodes[j][2] == 1);
            for(int k : graph[j]){
                if(depth[k] > i){
                    children.push_back(k);
                }
            }
            for(int k : children){
                oz[j] += oz[k];
                zo[j] += zo[k];
            }
            ll able = min(oz[j], zo[j]);
            ans += 2 * able * costs[j];
            oz[j] -= able;
            zo[j] -= able;
        }
    }
    if(oz[0] != 0 || zo[0] != 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}


