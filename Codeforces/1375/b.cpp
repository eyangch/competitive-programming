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
    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        int b[N][M];
        bool good = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> b[i][j];   
                int npos = 4;
                if(i == 0 || i == N-1){
                    npos--;
                }if(j == 0 || j == M-1){
                    npos--;
                }
                if(b[i][j] > npos){
                    good = false;
                }
            }
        }
        if(!good){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int npos = 4;
                if(i == 0 || i == N-1){
                    npos--;
                }if(j == 0 || j == M-1){
                    npos--;
                }
                cout << npos << " ";
            }cout << endl;
        }
    }
    return 0;
}


