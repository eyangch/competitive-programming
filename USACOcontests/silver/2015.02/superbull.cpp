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
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    int N; cin >> N;
    ll ids[N];
    for(int i = 0; i < N; i++) cin >> ids[i];
    ll treedist[N];
    bool vis[N];
    fill(vis, vis+N, false);
    fill(treedist, treedist+N, -1);
    treedist[0] = 0;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ll maxN = -1, maxidx = 0;
        for(int j = 0; j < N; j++){
            if(treedist[j] > maxN && !vis[j]){
                maxN = treedist[j];
                maxidx = j; 
            }
        }
        vis[maxidx] = true;
        ans += maxN;
        for(int j = 0; j < N; j++){
            treedist[j] = max(treedist[j], ids[maxidx] ^ ids[j]);
        }
    }
    cout << ans << endl;
    return 0;
}


