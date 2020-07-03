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

bool vis[1000][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    string b[N];
    bool is_blank = true;
    for(int i = 0; i < N; i++){
        cin >> b[i];
        for(char x : b[i]){
            if(x == '#'){
                is_blank = false;
            }
        }
    }
    if(is_blank){
        cout << 0 << endl;
        return 0;
    }
    int rowcnt[N];
    int colcnt[M];
    fill(rowcnt, rowcnt+N, 0);
    fill(colcnt, colcnt+M, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == 0 && b[i][j] == '#'){
                colcnt[j]++;
            }if(j == 0 && b[i][j] == '#'){
                rowcnt[i]++;
            }
            if(i > 0 && b[i-1][j] != b[i][j]){
                colcnt[j]++;
            }if(j > 0 && b[i][j-1] != b[i][j]){
                rowcnt[i]++;
            }
        }
    }
    if(max(*max_element(rowcnt, rowcnt+N), *max_element(colcnt, colcnt+M)) > 2){
        cout << -1 << endl;
        return 0;
    }
    if((*min_element(rowcnt, rowcnt+N) == 0) ^ (*min_element(colcnt, colcnt+M) == 0)){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(vis[i][j] || b[i][j] == '.'){
                continue;
            }
            ans++;
            queue<pii> bfs;
            bfs.push(pii(i, j));
            while(!bfs.empty()){
                pii idx = bfs.front();
                bfs.pop();
                int x = idx.first, y = idx.second;
                if(x < 0 || x >= N || y < 0 || y >= M || vis[x][y] || b[x][y] == '.'){
                    continue;
                }
                vis[x][y] = true;
                bfs.push(pii(x+1, y));
                bfs.push(pii(x-1, y));
                bfs.push(pii(x, y+1));
                bfs.push(pii(x, y-1));
            }
        }
    }
    cout << ans << endl;
    return 0;
}


