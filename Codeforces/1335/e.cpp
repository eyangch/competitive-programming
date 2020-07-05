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
        int N; cin >> N;
        int a[N];
        for(int i = 0; i < N; i++){
            cin >> a[i];  
            a[i]--; 
        }
        int pfx[200][N];
        vi revpfx0[200], revpfx[200];
        for(int i = 0; i < 200; i++){
            pfx[i][0] = (a[0] == i);
            for(int j = 1; j < N; j++){
                pfx[i][j] = pfx[i][j-1] + (a[j] == i);
            }
            for(int j = 0; j < N; j++){
                if(a[j] == i){
                    revpfx0[i].push_back(j);
                }
            }
            for(int j = N-1; j >= 0; j--){
                if(a[j] == i){
                    revpfx[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 200; i++){
            ans = max(ans, pfx[i][N-1]);
        }
        for(int i = 0; i < 200; i++){
            for(int j = 0; j < pfx[i][N-1]/2; j++){
                int start = revpfx0[i][j];
                int end = revpfx[i][j];
                int plus = 0;
                for(int k = 0; k < 200; k++){
                    plus = max(plus, pfx[k][end-1] - pfx[k][start]);
                }
                ans = max(ans, 2 * (j+1) + plus);
            }
        }
        cout << ans << endl;
    }
    return 0;
}


