/*
ID: sireric1
LANG: C++11
TASK: comehome
*/

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

struct node{
    int dest;
    int id;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout); 
    int P; cin >> P;
    vector<node> graph[128];
    int paths[P];
    for(int i = 0; i < P; i++){
        char u, v; cin >> u >> v;
        int l; cin >> l;
        paths[i] = l;
        node n1 = {(int)u, i};
        node n2 = {(int)v, i};
        graph[(int)u].push_back(n2);
        graph[(int)v].push_back(n1);
    }
    int dist[128];
    bool vis[128];
    fill(dist, dist+128, INT_MAX);
    fill(vis, vis+128, false);
    dist[(int)'Z'] = 0;
    while(true){
        int minN = INT_MAX;
        int minidx = 0;
        for(int j = 0; j < 128; j++){
            if(!vis[j] && dist[j] <= minN){
                minN = dist[j];
                minidx = j;   
            }
        }
        vis[minidx] = true;
        if(minidx < 90){
            cout << (char)minidx << " " << dist[minidx] << endl;
            break;
        }
        for(node j : graph[minidx]){
            if(vis[j.dest]){
                continue;
            }
            if(dist[minidx] + paths[j.id] < dist[j.dest]){
                dist[j.dest] = dist[minidx] + paths[j.id];
            }
        }
    }
    return 0;
}


