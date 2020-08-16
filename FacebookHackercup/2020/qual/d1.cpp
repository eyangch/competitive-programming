#include <bits/stdc++.h>

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

ll c[1000005];
bool vis[1000005];
ll dist[1000005];
set<pii> ds;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const ll LARGE = 1e15+23598798;
    freopen("d1.in", "r", stdin);
    ofstream fout("d1.txt");
    ll T; cin >> T;
    for(ll tc = 1; tc <= T; tc++){
        ll N, M; cin >> N >> M;   
        cout << "START TC " << tc << endl;
        for(ll i = 0; i < N; i++){
            cin >> c[i];
            if(c[i] == 0LL) c[i] = LARGE;
        }
        c[0] = c[N-1] = 0;
        cout << "finish input" << endl;
        fill(dist, dist+N, LARGE);
        ds.clear();
        for(ll i = 0; i <= M; i++){
            dist[i] = c[i];
            ds.insert(pii(dist[i], i));
        }
        bool good = true;
        for(ll i = M+1; i < N; i++){
            ds.erase(pii(dist[i-(M+1)], i-(M+1)));
            dist[i] = (*ds.begin()).first + c[i];
            if((*ds.begin()).first >= LARGE){
                good = false;
                break;
            }
            ds.insert(pii(dist[i], i));
            if(i % 100000 == 0) cout << i << endl;
        }
        cout << "finish sp" << endl;
        fout << "Case #" << tc << ": ";
        if(!good){
            fout << -1 << endl;
        }else{
            fout << dist[N-1] << endl;
        }
        cout << "END TC " << tc << endl;
    }
    return 0;
}


