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
        ll N; cin >> N;
        ll a[N];
        for(int i = 0; i < N; i++){
            cin >> a[i];   
        }
        if(N == 1){
            cout << a[0] << endl;
            continue;
        }
        ll adiff[N/2];
        ll bdiff[(N-1)/2];
        adiff[0] = a[1] - a[0];
        for(int i = 2; i+1 < N; i+=2){
            adiff[i/2] = adiff[i/2-1] + a[i+1] - a[i];
        }
        bdiff[0] = a[1] - a[2];
        for(int i = 3; i+1 < N; i+=2){
            bdiff[i/2] = bdiff[i/2-1] + a[i] - a[i+1];
        }
        ll minadiff[N/2];
        minadiff[0] = min(0LL, adiff[0]);
        for(int i = 1; i < N/2; i++){
            minadiff[i] = min(0LL, min(minadiff[i-1], adiff[i]));
        }
        ll minbdiff[(N-1)/2];
        minbdiff[0] = min(0LL, bdiff[0]);
        for(int i = 1; i < (N-1)/2; i++){
            minbdiff[i] = min(0LL, min(minbdiff[i-1], bdiff[i]));
        }
        ll ans = 0;
        for(int i = 0; i < N/2; i++){
            ans = max(ans, adiff[i] - minadiff[i]);
        }
        for(int i = 0; i < (N-1)/2; i++){
            ans = max(ans, bdiff[i] - minbdiff[i]);
        }
        for(int i = 0; i < N; i+=2){
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}


