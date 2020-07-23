#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};

bool vis[2001*2001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    ll A, B, N, M; cin >> A >> B >> N >> M;
    ll v[N], h[M];
    for(ll i = 0; i < N; i++) cin >> v[i];
    for(ll i = 0; i < M; i++) cin >> h[i];
    sort(v, v+N);
    sort(h, h+M);
    ll gapsV[M+1];
    gapsV[0] = h[0];
    for(ll i = 1; i < M; i++){
        gapsV[i] = h[i] - h[i-1];
    }
    gapsV[M] = B - h[M-1];
    ll gapsH[N+1];
    gapsH[0] = v[0];
    for(ll i = 1; i < N; i++){
        gapsH[i] = v[i] - v[i-1];
    }
    gapsH[N] = A - v[N-1];
    ll ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 0));
    while(!pq.empty()){
        pii lst = pq.top();
        pq.pop();
        if(vis[lst.second]) continue;
        vis[lst.second] = true;
        ans += lst.first;
        for(ll dir = 0; dir < 4; dir++){
            int i = lst.second / (M+1);
            int j = lst.second % (M+1);
            ll nx = i+dx[dir], ny = j+dy[dir];
            if(nx < 0 || nx > N || ny < 0 || ny > M || vis[(M+1) * nx + ny]){
                continue;
            }
            ll d = gapsV[j];
            if(nx == i){
                d = gapsH[i];
            }
            pq.push(pii(d, (M+1) * nx + ny));
        }
    }
    cout << ans << endl;
    return 0;
}


