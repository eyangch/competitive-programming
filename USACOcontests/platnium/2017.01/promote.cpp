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

int N, BIT[150000];
pii p[100000];
vi graph[100000];
int sz[100000];
int ans[100000];
vi tree;
int rev[100000];

int get(int x){
    int sum = 0;
    for(; x > 0; x -= x&-x){
        sum += BIT[x];
    }
    return sum;
}

void upd(int x, int dv){
    for(; x <= N; x += x&-x){
        BIT[x] += dv;
    }
}

int dfs(int id){
    sz[id] = 1;
    rev[id] = (int)tree.size();
    tree.push_back(id);
    for(int i : graph[id]){
        sz[id] += dfs(i);
    }
    return sz[id];
}

int main(){
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i].f;
        p[i].s = i;
    }
    sort(p, p+N, greater<pii>());
    for(int i = 1; i < N; i++){
        int u; cin >> u;
        graph[u-1].push_back(i);
    }
    dfs(0);
    for(int i = 0; i < N; i++){
        int x = rev[p[i].s]+1;
        ans[p[i].s] = get(x+sz[p[i].s]-1) - get(x);
        upd(x, 1);
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}


