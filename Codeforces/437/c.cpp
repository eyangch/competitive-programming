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

int main(){
    int n, m; cin >> n >> m;
    pii v[n], f[m];
    int vorig[n];
    vi graph[n];
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        vorig[i] = v[i].first;
        v[i].second = i;   
    }
    for(int i = 0; i < m; i++){
        cin >> f[i].first >> f[i].second;
        graph[f[i].first - 1].push_back(f[i].second - 1);
        graph[f[i].second - 1].push_back(f[i].first - 1);
    }
    sort(v, v + n, greater<pii>());
    int ans = 0;
    set<int> been;
    for(int i = 0; i < n; i++){
        int energy = 0;
        been.insert(v[i].second);
        for(int j = 0; j < (int)graph[v[i].second].size(); j++){
            if(been.find(graph[v[i].second][j]) != been.end()){
                continue;
            }
            energy += vorig[graph[v[i].second][j]];
        }
        ans += energy;
    }
    cout << ans << endl;
    return 0;
}


