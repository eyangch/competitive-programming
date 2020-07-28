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
    freopen("mooomoo.in", "r", stdin);
    freopen("mooomoo.out", "w", stdout);
    int N, B; cin >> N >> B;
    int V[B];
    for(int i = 0; i < B; i++){
        cin >> V[i];   
    }
    int vol[N];
    for(int i = 0; i < N; i++){
        cin >> vol[i];
    }
    int tvol[N];
    tvol[0] = vol[0];
    for(int i = 1; i < N; i++){
        tvol[i] = vol[i] - max(0, vol[i-1]-1);
    }
    ll cows[105];
    fill(cows, cows+105, INT_MAX);
    cows[0] = 0;
    sort(tvol, tvol+N);
    int pt = 0;
    ll ans = 0;
    for(int v = 0; v < 6000000; v++){
        if(v > 0) cows[v%105] = INT_MAX;
        for(int i = 0; i < B; i++){
            if(v - V[i] < 0) continue;
            cows[v%105] = min(cows[v%105], cows[(v-V[i])%105] + 1);
        }
        while(pt < N && tvol[pt] == v){
            ans += cows[v%105];
            pt++;
        }
    }
    cout << ans << endl;
    return 0;
}


