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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N; cin >> N;
        string a, b; cin >> a >> b;
        vi graph[20];
        bool ok = true;
        for(int i = 0; i < N; i++){
            if(a[i] > b[i]){
                cout << -1 << endl;
                ok = false;
                break;
            }else if(a[i] == b[i]) continue;
            graph[(int)a[i] - 'a'].push_back((int)b[i] - 'a');
            graph[(int)b[i] - 'a'].push_back((int)a[i] - 'a');
        }
        if(!ok){
            continue;
        }
        int ans = 0;
        bool vis[20];
        fill(vis, vis+20, false);
        for(int i = 0; i < 20; i++){
            if(vis[i]) continue;
            queue<int> bfs;
            bfs.push(i);
            while(!bfs.empty()){
                int idx = bfs.front();
                bfs.pop();
                if(vis[idx]) continue;
                vis[idx] = true;
                ans++;
                for(int j : graph[idx]){
                    bfs.push(j);
                }
            }
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}


