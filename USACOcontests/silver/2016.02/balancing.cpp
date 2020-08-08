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

int pfx[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N; cin >> N;
    set<int> xs, ys;
    int x[N], y[N];
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i]; 
        xs.insert(x[i]);
        ys.insert(y[i]); 
    }
    map<int, int> xtcx, cxtx, ytcy, cyty;
    int cnt = 1;
    for(int i : xs){
        xtcx[i] = cnt;
        cxtx[cnt] = i;
        cnt++;
    }
    cnt = 1;
    for(int i : ys){
        ytcy[i] = cnt;
        cyty[cnt] = i;
        cnt++;
    }
    for(int i = 0; i < N; i++){
        pfx[xtcx[x[i]]][ytcy[y[i]]]++;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            pfx[i][j] += pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            int ul = pfx[i][j];
            int ur = pfx[N][j] - ul;
            int bl = pfx[i][N] - ul;
            int br = pfx[N][N] - ur - bl - ul;
            //cout << i << " " << j << " " << ul << " " << ur << " " << bl << " " << br << endl;
            ans = min(ans, max({ul, ur, bl, br}));
        }
    }
    cout << ans << endl;
    return 0;
}


