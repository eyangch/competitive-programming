/*
ID: sireric1
LANG: C++11
TASK: rockers
*/

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

int dfs(int N, int T, int M, int (&a)[20], int (&fit)[20][20], int idx, int pidx, int depth){
    if(depth >= M){
        return 0;
    }
    int ret = fit[pidx][idx];
    int add = 0;
    for(int i = idx+1; i < N; i++){
        int x = dfs(N, T, M, a, fit, i, idx+1, depth+1);
        add = max(add, x);
    }
    return ret + add;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
    int N, T, M; cin >> N >> T >> M;
    int a[20];
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    int fit[20][20];
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int subarray[j-i+1];
            copy(a+i, a+j+1, subarray);
            sort(subarray, subarray+j-i+1);
            int sum = 0;
            int cnt = 0;
            for(; cnt < j-i+1; cnt++){
                sum += subarray[cnt];
                if(sum > T){
                    //cnt--;
                    break;
               }
            }
            fit[i][j] = cnt;
            //cout << "i: " << i << "   j: " << j << "   fit: " << fit[i][j] << "   sum: " << sum << endl;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        int x = dfs(N, T, M, a, fit, i, 0, 0);
        ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}


