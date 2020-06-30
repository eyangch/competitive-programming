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
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    int N; cin >> N;
    int rooms[N];
    for(int i = 0; i < N; i++){
        cin >> rooms[i];   
    }
    vi graph[N];
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    stack<pii> dfs;
    int val[2], count[2];
    val[0] = val[1] = count[0] = count[1] = 0;
    bool been[N];
    fill(been, been+N, false);
    dfs.push(pii(0, 0));
    while(!dfs.empty()){
        pii idx = dfs.top();
        dfs.pop();
        if(been[idx.first]) continue;
        been[idx.first] = true;
        val[idx.second % 2] += rooms[idx.first];
        count[idx.second % 2]++;
        for(int i : graph[idx.first]){
            dfs.push(pii(i, idx.second+1));
        }
    }
    int ans = 0;
    for(int i = 0; i < 2; i++){
        if((val[i] - val[1-i]) % 12 == 0 || (val[i] - val[1-i] - 1) % 12 == 0){
            ans += count[i];
        }
    }
    cout << ans << endl;
    return 0;
}


