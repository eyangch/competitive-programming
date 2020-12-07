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

map<string, int> m;
vi graph[10000];
bool vis[10000];

void dfs(int id){
    if(vis[id]) return;
    vis[id] = true;
    for(int i : graph[id]){
        dfs(i);
    }
}

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    int ans =0;
    int cnt = 0;
    string cbag = "";
    int parent = 0;
    while(cin >> nxt){
        if(nxt == "bag" || nxt == "bags"){
            if(m.find(cbag) == m.end()){
                m[cbag] = cnt;
                cnt++;
            }
            parent = m[cbag];
            cbag = "";
        }else if(nxt == "bag," || nxt == "bags,"){
            if(m.find(cbag) == m.end()){
                m[cbag] = cnt;
                cnt++;
            }
            graph[m[cbag]].push_back(parent);
            cbag = "";
        }else if(nxt == "bag." || nxt == "bags."){
            if(m.find(cbag) == m.end()){
                m[cbag] = cnt;
                cnt++;
            }
            graph[m[cbag]].push_back(parent);
            cbag = "";
        }else if(nxt.size() > 1 && nxt != "contain"){
            cbag += nxt;
        }
    }
    for(int i = 0; i < 15; i++){
        //cout << i << "        " << graph[i] << endl;
    }
    cout << m << endl;
    dfs(m["shinygold"]);
    for(int i = 0; i < 10000; i++){
        ans += vis[i];
    }
    cout << ans-1 << endl;
    return 0;
}



