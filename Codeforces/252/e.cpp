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

ll dist[360361];

ll bfs(ll num, ll K, ll end){
    fill(dist, dist+360361, -1);
    queue<pii> q;
    q.push(pii(num, 0));
    while(!q.empty()){
        ll x = q.front().first, d = q.front().second;
        q.pop();
        if(x == -1 || dist[x] >= 0){
            continue;
        }
        dist[x] = d;
        q.push(pii(x-1, d+1));
        for(ll i = 2; i <= K; i++){
            q.push(pii(x - (x%i), d+1));
        }
    }
    return dist[end];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll A, B, K; cin >> A >> B >> K;
    ll lcm = 1;
    for(ll i = 2; i <= 360360; i++){
        bool good = true;
        for(ll j = 2; j <= K; j++){
            if(i % j != 0){
                good = false;
                break;
            }
        }
        if(good){
            lcm = i;
            break;
        }
    }
    if(A / lcm == B / lcm){
        cout << bfs(A%lcm, K, B%lcm) << endl;
        return 0;
    }
    ll x = bfs(A%lcm, K, 0);
    ll y = bfs(lcm, K, B%lcm);
    ll z = bfs(lcm, K, 0);
    cout << x + y + ((A/lcm - B/lcm - 1) * z) << endl;
    return 0;
}


