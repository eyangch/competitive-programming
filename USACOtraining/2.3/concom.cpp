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

set<int> been;

bool dfs(int n, int c[101][101], int c1, int c2){
    int curr[101][101];
    copy(c[0], c[100] + 101, curr[0]);
    been.insert(c1);
    for(int i = 1; i < 101; i++){
        if(c[c1][i] > 50){
            if(i == c2){
                return true;
            }
            if(been.find(i) != been.end()){
                continue;
            }
            for(int j = 1; j < 101; j++){
                curr[i][j] += curr[c1][j];
            }
            if(dfs(n, curr, i, c2)){
                return true;
            }
        }
    }
    return false;
}

bool prelimbfs(int n, set<int> pown[101], int c1, int c2){
    set<int> cbn;
    cbn.insert(c1);
    queue<int> bfs;
    bfs.push(c1);
    while(!bfs.empty()){
        int idx = bfs.front();
        bfs.pop();
        if(idx == c2) return true;
        for(int x : pown[idx]){
            if(cbn.find(x) != cbn.end()) continue;
            cbn.insert(x);
            bfs.push(x);
        }
    }
    return false;
}

int main(){
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    int n; cin >> n;
    int c[101][101];
    fill(c[0], c[100] + 101, 0);
    set<int> pown[101];
    for(int i = 0; i < n; i++){
        int a, b, x; cin >> a >> b >> x;
        c[a][b] = x;
        if(c[a][b] > 50){
            pown[a].insert(b);
        }
    }
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 101; j++){
            been.clear();
            if(j == i) continue;   
            if(prelimbfs(n, pown, i, j) || dfs(n, c, i, j)){
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}


