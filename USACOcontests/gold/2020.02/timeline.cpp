#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

int N, M, C;
int s[100000];
vector<pii> graph[100000];
int indeg[100000];

void dfs(int id){
    for(pii i : graph[id]){
        s[i.f] = max(s[i.f], s[id] + i.s);
        indeg[i.f]--;
        if(indeg[i.f] == 0){
            dfs(i.f);
        }
    }
    indeg[id] = -1;
}

signed main(){
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    for(int i = 0; i < C; i++){
        int a, b, x; cin >> a >> b >> x;
        graph[a-1].push_back(pii(b-1, x));
        indeg[b-1]++;
    }
    for(int i = 0; i < N; i++){
        if(indeg[i] == 0){
            dfs(i);
        }
    }
    for(int i = 0; i < N; i++){
        cout << s[i] << endl; 
    }
    return 0;
}


