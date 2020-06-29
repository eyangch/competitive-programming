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
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    int W, H; cin >> W >> H;
    string m[2 * H + 1];
    getline(cin, m[0]);
    for(int i = 0; i < 2 * H + 1; i++){
        getline(cin, m[i]);
    }
    vector<pii> srooms;
    for(int i = 1; i < 2 * H + 1; i += 2){
        for(int j = 1; j < 2 * W + 1; j += 2){
            if(i == 1 && m[i-1][j] == ' '){
                srooms.push_back(pii(i, j));
            }if(i == 2 * H - 1 && m[i+1][j] == ' '){
                srooms.push_back(pii(i, j));
            }if(j == 1 && m[i][j-1] == ' '){
                srooms.push_back(pii(i, j));
            }if(j == 2 * W - 1 && m[i][j+1] == ' '){
                srooms.push_back(pii(i, j));
            }
        }
    }
    int minDist[2 * H + 1][2 * W + 1];
    fill(minDist[0], minDist[2 * H] + 2 * W + 1, INT_MAX);
    for(pii start : srooms){
        queue<pair<pii, int>> bfs;
        bfs.push(make_pair(start, 1));
        set<pii> been;
        while(!bfs.empty()){
            pair<pii, int> idx = bfs.front();
            bfs.pop();
            if(been.find(idx.first) != been.end()){
                continue;
            }
            been.insert(idx.first);
            int x = idx.first.first, y = idx.first.second;
            minDist[x][y] = min(minDist[x][y], idx.second);
            if(x > 1 && m[x-1][y] == ' '){
                bfs.push(make_pair(pii(x-2, y), idx.second + 1));
            }
            if(x < 2 * H - 1 && m[x+1][y] == ' '){
                bfs.push(make_pair(pii(x+2, y), idx.second + 1));
            }
            if(y > 1 && m[x][y-1] == ' '){
                bfs.push(make_pair(pii(x, y-2), idx.second + 1));
            }
            if(y < 2 * W - 1 && m[x][y+1] == ' '){
                bfs.push(make_pair(pii(x, y+2), idx.second + 1));
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < 2 * H + 1; i+=2){
        for(int j = 1; j < 2 * W + 1; j+=2){
            ans = max(ans, minDist[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}


