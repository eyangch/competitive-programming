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
    freopen("fortmoo.in", "r", stdin);
    freopen("fortmoo.out", "w", stdout);
    int N, M; cin >> N >> M;
    string grid[N];
    for(int i = 0; i < N; i++){
        cin >> grid[i];   
    }
    bool swmp[N][M];
    fill(swmp[0], swmp[N-1]+M, false);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 'X'){
                swmp[i][j] = true;
            }
        }
    }
    int pfx[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            pfx[i][j] = swmp[i][j];
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < M; j++){
            pfx[i][j] += pfx[i-1][j];
        }
    }
    int O_o_o_O = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int startloc = -1;
            for(int k = 0; k < M; k++){
                if(swmp[i][k] || swmp[j][k]){
                    startloc = -1;
                    continue;
                }
                if(pfx[i][k] == pfx[j][k]){
                    if(startloc == -1){
                        startloc = k;
                    }
                    pii ul = pii(i, startloc), lr = pii(j, k);
                    if(O_o_o_O < (lr.first - ul.first + 1) * (lr.second - ul.second + 1)){
                        O_o_o_O = (lr.first - ul.first + 1) * (lr.second - ul.second + 1);
                        //cout << ul << "     " << lr << endl;
                    }
                }
            }
        }
    }
    cout << O_o_o_O << endl;
    return 0;
}


