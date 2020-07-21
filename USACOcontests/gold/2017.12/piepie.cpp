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

struct bfs_s{
    pii x;
    int dist;
    int idx;
    bool turn;
};

set<pair<pii, int>> p[2];
queue<bfs_s> bfs;
int dist[100000];
bfs_s nxt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    int N, D; cin >> N >> D;
    fill(dist, dist+N, -2);
    for(int i = 0; i < N; i++){  
        pii x; cin >> x.second >> x.first;
        p[0].insert(make_pair(x, i));
        if(x.first == 0){
            nxt = {x, 0, i, 0};
            bfs.push(nxt);
            dist[i] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        pii x; cin >> x.first >> x.second;
        p[1].insert(make_pair(x, i));
        if(x.first == 0){
            nxt = {x, 0, i, 1};
            bfs.push(nxt);
        }
    }
    while(!bfs.empty()){
        bfs_s cur = bfs.front();
        bfs.pop();
        pii x = cur.x;
        int cdist = cur.dist;
        int idx = cur.idx;
        bool turn = cur.turn;
        if(p[turn].find(make_pair(x, idx)) == p[turn].end()){
            continue;
        }
        if(turn == 0) dist[idx] = cdist;
        p[turn].erase(make_pair(x, idx));
        int lb = x.second - D;
        int ub = x.second;
        auto it = p[!turn].lower_bound(make_pair(pii(lb, 0), 0));
        for(; it != p[!turn].end(); it++){
            if((*it).first.first > ub){
                break;
            }
            nxt = {(*it).first, cdist+1, (*it).second, !turn};
            bfs.push(nxt);
        }
    }
    for(int i = 0; i < N; i++){
        cout << dist[i]+1 << endl;
    }
    return 0;
}


