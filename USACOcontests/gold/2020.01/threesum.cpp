#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

int N, Q;
int A[5000], srtA[5000];
int M;
int mpDown[2000001];
int occ[5000];
int vis[5000][160];
ll dp[5000][5000];

ll dfs(int l, int r){
    if(l+1 >= r){
        return 0;
    }
    if(vis[l][r/32] & (1 << (r%32))){
        return dp[l][r];
    }
    dp[l][r] += dfs(l+1, r) + dfs(l, r-1) - dfs(l+1, r-1);
    vis[l][r/32] |= 1 << (r%32);
    return dp[l][r];
}

signed main(){
    setIO("threesum");
    cin >> N >> Q;
    fill(mpDown, mpDown+2000001, 1e9);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(mpDown[A[i]+1000000] == 1e9){
            mpDown[A[i]+1000000] = M++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            occ[j] = 0;
        }
        for(int j = i+2; j < N; j++){
            if(A[j-1]+1000000 >= 0 && A[j-1]+1000000 <= 2000000 && mpDown[A[j-1]+1000000] < 1e9){
                occ[mpDown[A[j-1]+1000000]]++;
            }
            int t = -(A[i] + A[j]) + 1000000;
            if(t < 0 || t > 2000000 || mpDown[t] == 1e9) continue;
            dp[i][j] = occ[mpDown[t]];
        }
    }
    for(int i = 0; i < Q; i++){
        int a, b; cin >> a >> b;
        cout << dfs(a-1, b-1) << endl;   
    }
    return 0;
}


