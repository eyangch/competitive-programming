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
        int N, K; cin >> N >> K;
        int a[N], w[K];
        for(int i = 0; i < N; i++){
            cin >> a[i];   
        }
        for(int i = 0; i < K; i++){
            cin >> w[i];
        }
        sort(a, a+N);
        sort(w, w+K);
        int lo = 0;
        int hi = N-1;
        ll ans = 0;
        for(int i = 0; i < K; i++){
            if(w[i] == 1){
                ans += a[hi] * 2;
                hi--;
            }else{
                break;
            }
        }
        for(int i = K-1; i >= 0; i--){
            if(w[i] == 1){
                break;
            }else{
                ans += a[hi] + a[lo];
                hi--;
                lo += w[i]-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


