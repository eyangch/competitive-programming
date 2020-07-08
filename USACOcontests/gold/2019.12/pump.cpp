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

struct dat{
    int idx;
    int cost;
    int mwidth;
    int midx;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int N, M; cin >> N >> M;
    pii pipes[M];
    vector<pii> graph[N];
    for(int i = 0; i < M; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        pipes[i] = pii(c, d);
        graph[a-1].push_back(pii(b-1, i));
        graph[b-1].push_back(pii(a-1, i));
    }
    bool usable[M];
    fill(usable, usable+M, true);
    ll ans = 0;
    while(true){
        dat bn[N];
        queue<dat> bfs;
        dat tmp_dat = {0, 0, INT_MAX, -1};
        dat fill_dat = {-1, INT_MAX, 0, -1};
        fill(bn, bn+N, fill_dat);
        bfs.push(tmp_dat);
        while(!bfs.empty()){
            dat idx = bfs.front();
            bfs.pop();
            for(pii i : graph[idx.idx]){
                if(!usable[i.second]){
                    continue;
                }
                if(idx.cost + pipes[i.second].first < bn[i.first].cost){
                    bn[i.first].cost = idx.cost + pipes[i.second].first;
                    bn[i.first].idx = i.first;
                    if(idx.mwidth < pipes[i.second].second){
                        bn[i.first].mwidth = idx.mwidth;
                        bn[i.first].midx = idx.midx;
                    }else{
                        bn[i.first].mwidth = pipes[i.second].second;
                        bn[i.first].midx = i.second;
                    }
                    bfs.push(bn[i.first]);
                }
            }
        }
        if(bn[N-1].idx == -1){
            break;
        }
        ans = max(ans, 1000000LL * bn[N-1].mwidth / bn[N-1].cost);
        usable[bn[N-1].midx] = false;
    }
    cout << ans << endl;
    return 0;
}


