#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"
#define int ll

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

void setIO(string s){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(s != ""){
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}

int N, M, Q;
int d[500][500];

signed main(){
    setIO("");
    cin >> N >> M >> Q;
    fill(d[0], d[N-1]+N, 1e14);
    for(int i = 0; i < N; i++){
        d[i][i] = 0;
    }
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        d[a-1][b-1] = d[b-1][a-1] = min(d[a-1][b-1], c);
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for(int i = 0; i < Q; i++){
        int a, b; cin >> a >> b;
        cout << (d[a-1][b-1] >= 1e14 ? -1 : d[a-1][b-1]) << endl;
    }
    return 0;
}


