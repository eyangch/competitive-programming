#include <bits/stdc++.h>
#define f first
#define s second

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

int dist[1000101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int N, M; cin >> N >> M;
    int a[N], b[N], c[M], d[M];
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < M; i++){
        cin >> c[i] >> d[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(c[j] - a[i] >= 0){
                dist[c[j] - a[i]] = max(dist[c[j] - a[i]], d[j] - b[i] + 1);
            }
        }
    }
    int mx = 0;
    int ans = INT_MAX;
    for(int i = 1000100; i >= 0; i--){
        mx = max(dist[i], mx);
        ans = min(ans, i + mx);
        //cout << ans << " " << dist[i] << " " << mx << endl;
    }
    cout << ans << endl;
    return 0;
}


