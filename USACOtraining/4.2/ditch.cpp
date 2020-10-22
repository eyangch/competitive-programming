/*
ID: sireric1
LANG: C++11
TASK: ditch
*/

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
ll cap[210][210];
bool vis[210];
ll prevnode[210];
ll flow[210];

int main(){
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(ll i = 0; i < N; i++){
        ll s, e, c; cin >> s >> e >> c;
        cap[s-1][e-1] += c;
    }
    ll tflow = 0;
    while(true){
        for(ll i = 0; i < M; i++){
            prevnode[i] = -1;
            flow[i] = 0;
            vis[i] = false;
        }
        flow[0] = 1e12;
        ll maxflow, maxloc = -1;
        while(true){
            maxflow = 0;
            maxloc = -1;
            for(ll i = 0; i < M; i++){
                if(flow[i] > maxflow && !vis[i]){
                    maxflow = flow[i];
                    maxloc = i;
                }
            }
            if(maxloc == -1 || maxloc == M-1){
                break;
            }
            vis[maxloc] = true;
            for(ll i = 0; i < M; i++){
                if(flow[i] < min(maxflow, cap[maxloc][i])){
                    prevnode[i] = maxloc;
                    flow[i] = min(maxflow, cap[maxloc][i]);
                }
            }
        }
        if(maxloc == -1){
            break;
        }
        tflow += flow[M-1];
        ll currnode = M-1;
        while(currnode != 0){
            ll nxtnode = prevnode[currnode];
            cap[nxtnode][currnode] -= flow[M-1];
            cap[currnode][nxtnode] += flow[M-1];
            currnode = nxtnode;
        }
    }
    cout << tflow << endl;
    return 0;
}


