/*
ID: sireric1
LANG: C++11
TASK: fence6
*/

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int N, M; 
vi desc[200];
vector<pii> graph[200];

int main(){
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        int s, l, n1, n2; cin >> s >> l >> n1 >> n2;
        vi a, b;
        a.push_back(s);
        b.push_back(s);
        for(int j = 0; j < n1; j++){
            int x; cin >> x;
            a.push_back(x);
        }
        for(int j = 0; j < n2; j++){
            int x; cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int fa = -1, fb = -1;
        for(int j = 0; j < M; j++){
            if(desc[j] == a){
                fa = j;
            }
            if(desc[j] == b){
                fb = j;
            }
        }
        if(fa == -1){
            fa = M;
            desc[fa] = a;
            M++;
        }
        if(fb == -1){
            fb = M;
            desc[fb] = b;
            M++;
        }
        graph[fa].push_back(pii(fb, l));
        graph[fb].push_back(pii(fa, l));
    }
    int ans = 1e9;
    for(int i = 0; i < M; i++){
        int dist[M];
        fill(dist, dist+M, 1e9);
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push(pipii(0, pii(i, -1)));
        while(!pq.empty()){
            int d = pq.top().f, id = pq.top().s.f, pid = pq.top().s.s;
            pq.pop();
            if(dist[id] < 1e9){
                ans = min(ans, dist[id] + d);
                break;
            }
            dist[id] = d;
            for(pii j : graph[id]){
                if(j.f != pid){
                    pq.push(pipii(d + j.s, pii(j.f, id)));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


