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
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string b[n];
        for(int i = 0; i < n; i++){
            cin >> b[i];   
        }
        bool good = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(b[i][j] == 'B'){
                    if(i > 0 && b[i-1][j] == 'G') good = false;
                    if(i < n-1 && b[i+1][j] == 'G') good = false;
                    if(j > 0 && b[i][j-1] == 'G') good = false;
                    if(j < m-1 && b[i][j+1] == 'G') good = false;
                }
            }
        }
        if(!good){
            cout << "No" << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(b[i][j] == 'B'){
                    if(i > 0 && b[i-1][j] != 'B') b[i-1][j] = '#';
                    if(i < n-1 && b[i+1][j] != 'B') b[i+1][j] = '#';
                    if(j > 0 && b[i][j-1] != 'B') b[i][j-1] = '#';
                    if(j < m-1 && b[i][j+1] != 'B') b[i][j+1] = '#';
                }
            }
        }
        //for(string i : b) cout << i << endl;
        bool out[n][m];
        fill(out[0], out[n-1] + m, false);
        queue<pii> bfs;
        bfs.push(pii(n-1, m-1));
        while(!bfs.empty()){
            pii idx = bfs.front();
            bfs.pop();
            int x = idx.first, y = idx.second;
            if(x < 0 || x >= n || y < 0 || y >= m || out[x][y] || b[x][y] == '#') continue;
            out[x][y] = true;
            bfs.push(pii(x-1, y));
            bfs.push(pii(x+1, y));
            bfs.push(pii(x, y-1));
            bfs.push(pii(x, y+1));
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((b[i][j] == 'G' && out[i][j] == false) || (b[i][j] == 'B' && out[i][j] == true)){
                    good = false;
                    break;
                }
            }
        }
        if(good){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}


