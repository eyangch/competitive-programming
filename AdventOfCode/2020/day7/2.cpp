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
vector<pii> graph[10000];

int dfs(int id){
    int ret = 1;
    for(pii i : graph[id]){
        ret += i.s * dfs(i.f);
    }
    cout << id << " "<< ret << endl;
    return ret;
}

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    int ans =0;
    int cnt = 0;
    string cbag = "";
    int numbag = 0;
    int parent = 0;
    while(cin >> nxt){
        if(nxt == "bag" || nxt == "bags"){
            if(m.find(cbag) == m.end()){
                m[cbag] = cnt;
                cnt++;
            }
            parent = m[cbag];
            cbag = "";
        }else if(nxt == "bag," || nxt == "bags," || nxt == "bag." || nxt == "bags."){
            if(m.find(cbag) == m.end()){
                m[cbag] = cnt;
                cnt++;
            }
            if(cbag != "noother"){
                graph[parent].push_back(pii(m[cbag], numbag));
            }
            cbag = "";
        }else if(nxt.size() == 1){
            numbag = nxt[0] - '0';
        }else if(nxt != "contain"){
            cbag += nxt;
        }
    }
    cout << dfs(m["shinygold"])-1 << endl;
    return 0;
}




