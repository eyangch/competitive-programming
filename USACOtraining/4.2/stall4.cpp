/*
ID: sireric1
LANG: C++11
TASK: stall4
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
ll cap[500][500];
bool vis[500];
ll prevnode[500];
ll flow[500];

int main(){
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(ll i = 1; i <= N; i++){
        int s; cin >> s;
        cap[0][i] = 1;
        for(int j = 0; j < s; j++){
            int x; cin >> x;
            cap[i][N+x] = 1;
        }
    }
    for(int i = 1; i <= M; i++){
        cap[N+i][N+M+1] = 1;
    }
    ll tflow = 0;
    int tn = N+M+2;
    while(true){
        for(ll i = 0; i < tn; i++){
            prevnode[i] = -1;
            flow[i] = 0;
            vis[i] = false;
        }
        flow[0] = 1e12;
        ll maxflow, maxloc = -1;
        while(true){
            maxflow = 0;
            maxloc = -1;
            for(ll i = 0; i < tn; i++){
                if(flow[i] > maxflow && !vis[i]){
                    maxflow = flow[i];
                    maxloc = i;
                }
            }
            if(maxloc == -1 || maxloc == tn-1){
                break;
            }
            vis[maxloc] = true;
            for(ll i = 0; i < tn; i++){
                if(flow[i] < min(maxflow, cap[maxloc][i])){
                    prevnode[i] = maxloc;
                    flow[i] = min(maxflow, cap[maxloc][i]);
                }
            }
        }
        if(maxloc == -1){
            break;
        }
        tflow += flow[tn-1];
        ll currnode = tn-1;
        while(currnode != 0){
            ll nxtnode = prevnode[currnode];
            cap[nxtnode][currnode] -= flow[tn-1];
            cap[currnode][nxtnode] += flow[tn-1];
            currnode = nxtnode;
        }
    }
    cout << tflow << endl;
    return 0;
}


