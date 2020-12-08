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

vector<pii> p;
bool vis[10000];

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    int ans =0;
    int progloc = 0;
    bool instruc = true;
    int cinst = 0;
    while(cin >> nxt){
        if(instruc){
            if(nxt == "nop"){
                cinst = 0;
            }else if(nxt == "acc"){
                cinst = 1;
            }else{
                cinst = 2;
            }
        }else{
            p.push_back(pii(cinst, stoi(nxt)));
        }
        instruc = !instruc;
    }
    while(true){
        if(vis[progloc]) break;
        if(p[progloc].f == 0){
            progloc++;
        }else if(p[progloc].f == 1){
            ans += p[progloc].s;
            progloc++;
        }else{
            progloc += p[progloc].s;
        }
    }
    return 0;
}



