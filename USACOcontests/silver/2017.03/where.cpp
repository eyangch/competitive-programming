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

struct rect{
    int x1;
    int y1;
    int x2;
    int y2;
};

bool works(int N, char (&grid)[20][20], rect r){
    bool occ[26];
    fill(occ, occ+26, 0);
    for(int i = r.x1; i <= r.x2; i++){
        for(int j = r.y1; j <= r.y2; j++){
            occ[(int)(grid[i][j] - 'A')] = 1;
        }
    }
    int diff = 0;
    for(int i = 0; i < 26; i++){
        diff += occ[i];
    }
    if(diff != 2){
        return false;
    }
    int regions[26];
    fill(regions, regions+26, 0);
    bool visited[N][N];
    fill(visited[0], visited[N-1]+N, false);
    for(int i = r.x1; i <= r.x2; i++){
        for(int j = r.y1; j <= r.y2; j++){
            if(visited[i][j] || regions[(int)(grid[i][j] - 'A')] > 1) continue;
            if(regions[(int)(grid[i][j] - 'A')] == 1){
                regions[(int)(grid[i][j] - 'A')]++;
            }else{
                regions[(int)(grid[i][j] - 'A')]++;
                char rc = grid[i][j];
                stack<pii> ff;
                ff.push(pii(i, j));
                while(!ff.empty()){
                    int x = ff.top().first, y = ff.top().second;
                    ff.pop();
                    if(x < r.x1 || x > r.x2 || y < r.y1 || y > r.y2 || visited[x][y] || grid[x][y] != rc){
                        continue;
                    }
                    //cout << "X: " << x << "  Y: " << y << endl;
                    visited[x][y] = true;
                    ff.push(pii(x+1, y));
                    ff.push(pii(x-1, y));
                    ff.push(pii(x, y+1));
                    ff.push(pii(x, y-1));
                }
            }
        }
    }
    bool good = true;
    bool one = false, twoplus = false;
    for(int i = 0; i < 26; i++){
        if(regions[i] == 1){
            if(one){
                good = false;
                break;
            }else{
                one = true;
            }
        }else{
            twoplus = true;
        }
    }
    return (good && one && twoplus);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int N; cin >> N;
    char grid[20][20];
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < N; j++){
            grid[i][j] = s[j];
        }
    }
    vector<rect> pcls;
    for(int x1 = 0; x1 < N; x1++){
        for(int y1 = 0; y1 < N; y1++){
            for(int x2 = N-1; x2 >= 0; x2--){
                for(int y2 = N-1; y2 >= 0; y2--){
                    int good = true;
                    for(rect r : pcls){
                        if(x1 >= r.x1 && y1 >= r.y1 && x2 <= r.x2 && y2 <= r.y2){
                            good = false;
                            break;
                        }
                    }
                    if(!good){
                        continue;
                    }
                    rect curr = {x1, y1, x2, y2};
                    if(works(N, grid, curr)){
                        pcls.push_back(curr);
                    }
                }
            }
        }
    }
    cout << pcls.size() << endl;
    return 0;
}


