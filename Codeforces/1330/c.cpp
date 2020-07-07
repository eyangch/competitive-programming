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
    int N, M; cin >> N >> M;
    ll l[M];
    for(int i = 0; i < M; i++){
        cin >> l[i];
    }
    bool good = true;
    for(int i = 0; i < M; i++){
        if(i + l[i] > N){
            good = false;
            break;
        }
    }
    ll x = 0;
    for(int i = 0; i < M; i++){
        x += l[i];
    }
    if(x < N){
        good = false;
    }
    if(!good){
        cout << -1 << endl;
        return 0;
    }
    ll ans[M];
    for(int i = 0; i < M; i++){
        ans[i] = i;
    }
    ll prev = N;
    for(ll i = M-1; i >= 0; i--){
        ans[i] = max(i, prev - l[i]);
        prev -= l[i];
    }
    for(int i = 0; i < M; i++){
        cout << ans[i]+1 << " ";
    }cout << endl;
    return 0;
}


