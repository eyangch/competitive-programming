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

struct dfs_s{
    int idx;
    char ctype;
    int c;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int N, M; cin >> N >> M;
    string cows; cin >> cows;
    vi graph[100005];
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    int segs[100005];
    fill(segs, segs+N, -1);
    stack<dfs_s> dfs_segs;
    dfs_s psh = {0, cows[0], 0};
    dfs_segs.push(psh);
    while(!dfs_segs.empty()){
        dfs_s idx = dfs_segs.top();
        dfs_segs.pop();
        if(segs[idx.idx] != -1){
            continue;
        }
        if(cows[idx.idx] != idx.ctype){
            idx.c = idx.idx;
        }
        idx.ctype = cows[idx.idx];
        segs[idx.idx] = idx.c;
        for(int i : graph[idx.idx]){
            psh = {i, idx.ctype, idx.c};
            dfs_segs.push(psh);
        }
    }
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        char c; cin >> c;
        if(cows[a-1] == c || segs[a-1] != segs[b-1]){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
