#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll dfs(ll N, ll (&a)[200000], vi (&c)[200000], ll idx, ll &ans, stack<ll> &s, queue<ll> &q){
    for(ll i : c[idx]){
        a[idx] += dfs(N, a, c, i, ans, s, q);
    }
    ans += a[idx];
    if(a[idx] < 0){
        s.push(idx);
        return 0;
    }
    q.push(idx);
    return a[idx];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N; cin >> N;
    ll a[200000], b[N];
    for(ll i = 0; i < N; i++){
        cin >> a[i];   
    }
    for(ll i = 0; i < N; i++){
        cin >> b[i];
    }
    vi c[200000];
    for(ll i = 0; i < N; i++){
        if(b[i] == -1) continue;
        c[b[i]-1].push_back(i);
    }
    ll ans = 0;
    stack<ll> s;
    queue<ll> q;
    for(ll i = 0; i < N; i++){
        if(b[i] == -1){
            dfs(N, a, c, i, ans, s, q);
        }
    }
    cout << ans << endl;
    while(!q.empty()){
        cout << q.front()+1 << " ";
        q.pop();
    }
    while(!s.empty()){
        cout << s.top()+1 << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}


