#include <bits/stdc++.h>
#define f first
#define s second

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

ll MOD = 1e9+9;

int N, M, K;
int fj[1000];
int fp[1000];
ll dp[1000][1001][10];
ll pfx[1000][1001][10];

int main(){
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> fj[i];
    }
    for(int i = 0; i < M; i++){
        cin >> fp[i];
    }
    sort(fj, fj+N);
    sort(fp, fp+M);
    for(int i = K-1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            for(int k = -1; k < M; k++){
                if(fp[k] < fj[j]){
                    int fp_start = k+1;
                    int fp_end = lower_bound(fp+max(0, k), fp+M, fj[j]) - fp;
                    if(i == K-1){
                        dp[j][k+1][i] = fp_end - fp_start;
                    }else{
                        dp[j][k+1][i] = pfx[N-1][fp_end][i+1];
                        dp[j][k+1][i] -= pfx[j][fp_end][i+1];
                        dp[j][k+1][i] -= pfx[N-1][fp_start][i+1];
                        dp[j][k+1][i] += pfx[j][fp_start][i+1];
                    }
                }
                dp[j][k+1][i] = (dp[j][k+1][i] % MOD + MOD) % MOD;
                pfx[j][k+1][i] = dp[j][k+1][i];
                if(j > 0){
                    pfx[j][k+1][i] += pfx[j-1][k+1][i];
                }
                if(k+1 > 0){
                    pfx[j][k+1][i] += pfx[j][k][i];
                }
                if(j > 0 && k+1 > 0){
                    pfx[j][k+1][i] -= pfx[j-1][k][i];
                }
                pfx[j][k+1][i] = (pfx[j][k+1][i] % MOD + MOD) % MOD;
            }
        }
    }
    cout << pfx[N-1][0][0] << endl;
    return 0;
}

