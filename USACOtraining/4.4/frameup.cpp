/*
ID: sireric1
LANG: C++11
TASK: frameup
*/

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

void topSort(int H, int W, bool (&adj)[26][26], vi &curr, int (&indegree)[26], bool (&vis)[26], vector<vi> &ans){
    int ops = 0;
    for(int i = 0; i < 26; i++){
        if(indegree[i] == 0 && !vis[i]){
            ops++;
            curr.push_back(i);
            vis[i] = true;
            for(int j = 0; j < 26; j++){
                indegree[j] -= adj[i][j];
            }
            topSort(H, W, adj, curr, indegree, vis, ans);
            curr.pop_back();
            vis[i] = false;
            for(int j = 0; j < 26; j++){
                indegree[j] += adj[i][j];
            }
        }
    }
    if(!ops){
        ans.push_back(curr);
    }
}

int main(){
    freopen("frameup.in", "r", stdin);
    freopen("frameup.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W; cin >> H >> W; 
    string grid[H];
    for(int i = 0; i < H; i++){
        cin >> grid[i];
    }
    int x1[26], y1[26], x2[26], y2[26];
    fill(x1, x1+26, INT_MAX); // height
    fill(y1, y1+26, INT_MAX); // width
    fill(x2, x2+26, -1); // height
    fill(y2, y2+26, -1); // width
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(grid[i][j] == '.'){
                continue;
            }
            int cid = grid[i][j] - 'A';
            x1[cid] = min(x1[cid], i);
            x2[cid] = max(x2[cid], i);
            y1[cid] = min(y1[cid], j);
            y2[cid] = max(y2[cid], j);
        }
    }
    bool adj[26][26];
    fill(adj[0], adj[25]+26, false);
    for(int let = 0; let < 26; let++){
        if(x2[let] == -1) continue;
        for(int x = x1[let]; x <= x2[let]; x++){
            int topline = grid[x][y1[let]] - 'A';
            int botline = grid[x][y2[let]] - 'A';
            adj[topline][let] = true;
            adj[botline][let] = true;
        }
        for(int y = y1[let]; y <= y2[let]; y++){
            int topline = grid[x1[let]][y] - 'A';
            int botline = grid[x2[let]][y] - 'A';
            adj[topline][let] = true;
            adj[botline][let] = true;
        }
    }
    int indegree[26];
    fill(indegree, indegree+26, 0);
    for(int i = 0; i < 26; i++){
        if(x2[i] == -1){
            indegree[i] = INT_MAX;
            continue;
        }
        for(int j = 0; j < 26; j++){
            if(i == j) continue;
            if(adj[j][i]){
                indegree[i]++;
            }
        }
    }
    vector<vi> ans;
    vi curr;
    bool vis[26];
    fill(vis, vis+26, false);
    topSort(H, W, adj, curr, indegree, vis, ans);
    for(int i = 0; i < (int)ans.size(); i++){
        reverse(ans[i].begin(), ans[i].end());
    }
    sort(ans.begin(), ans.end());
    for(vi i : ans){
        for(int j : i){
            cout << (char)(j+'A');
        }
        cout << endl;
    }
    return 0;
}


