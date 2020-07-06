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

bool works(int N, pii c[1000], ll x){
    vi graph[N];
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            ll cdist = pow(c[i].first - c[j].first, 2) + pow(c[i].second - c[j].second, 2);
            if(cdist <= x){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    bool vis[N];
    fill(vis, vis+N, false);
    queue<int> bfs;
    bfs.push(0);
    while(!bfs.empty()){
        int idx = bfs.front();
        bfs.pop();
        if(vis[idx]){
            continue;
        }
        vis[idx] = true;
        for(int i : graph[idx]){
            bfs.push(i);
        }
    }
    for(bool i : vis){
        if(!i){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int N; cin >> N;
    pii c[1000];
    for(int i = 0; i < N; i++){
        cin >> c[i].first >> c[i].second;   
    }
    ll lo = 0;
    ll hi = 2 * pow(25000, 2);
    ll mid = 0;
    while(lo < hi){
        mid = (lo+hi)/2;
        bool ok = works(N, c, mid);
        if(ok){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    while(works(N, c, mid)) mid--;
    while(!works(N, c, mid)) mid++;
    cout << mid << endl;
    return 0;
}


