#include <bits/stdc++.h>
#define f first
#define s second

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

ll N, M;
ll sx, sy, fx, fy;
ll x[100001], y[100001];
ll xid[100001], yid[100001];
ll dist[100001];

bool cmpx(ll a, ll b){
    if(x[a] == x[b]){
        return a < b;
    }
    return x[a] < x[b];
}
bool cmpy(ll a, ll b){
    if(y[a] == y[b]){
        return a < b;
    }
    return y[a] < y[b];
}

ll distf1(ll a, ll b){
    ll n1 = abs(x[a] - x[b]);
    ll n2 = abs(y[a] - y[b]);
    //cout << "DISTF1: " << a << " " << b << " ==== " << n1 << " " << n2 << endl;
    return min(n1, n2);
}

ll distf2(ll a){
    return abs(fx - x[a]) + abs(fy - y[a]);
}

void addPQ(priority_queue<pii, vector<pii>, greater<pii>> &pq, ll cidx, ll cdist){
    ll f1x = lower_bound(xid, xid+M+1, cidx, cmpx) - xid;
    if(f1x+1 < M+1){
        pq.push(pii(distf1(xid[f1x+1], cidx) + cdist, xid[f1x+1]));
    }
    if(f1x-1 >= 0){
        pq.push(pii(distf1(xid[f1x-1], cidx) + cdist, xid[f1x-1]));
    }
    ll f1y = lower_bound(yid, yid+M+1, cidx, cmpy) - yid;
    if(f1y+1 < M+1){
        pq.push(pii(distf1(yid[f1y+1], cidx) + cdist, yid[f1y+1]));
    }
    if(f1y-1 >= 0){
        pq.push(pii(distf1(yid[f1y-1], cidx) + cdist, yid[f1y-1]));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin >> sx >> sy >> fx >> fy;
    x[0] = sx;
    y[0] = sy;
    for(ll i = 1; i <= M; i++){
        cin >> x[i] >> y[i];
    }
    iota(xid, xid+M+1, 0);
    iota(yid, yid+M+1, 0);
    sort(xid, xid+M+1, cmpx);
    sort(yid, yid+M+1, cmpy);
    fill(dist, dist+M+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 0));
    int cntr = 0;
    while(!pq.empty()){
        ll d = pq.top().f, cid = pq.top().s;
        pq.pop();
        if(dist[cid] != INT_MAX){
            continue;
        }
        //cout << "PQ RuN : " << cid << " " << d << endl;
        //assert((x[cid] != fx || y[cid] != fy));
        dist[cid] = d;
        addPQ(pq, cid, d);
        cntr++;
    }
    assert(cntr == M+1);
    ll ans = INT_MAX;
    for(ll i = 0; i <= M; i++){
        ans = min(ans, dist[i] + distf2(i));
        //cout << distf1(0, i) << endl;
        //cout << dist[i] << " " << distf2(i) << endl;
    }
    cout << ans << endl;
    return 0;
}


