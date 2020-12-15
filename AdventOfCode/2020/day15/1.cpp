#include <bits/stdc++.h>
#define f first
#define s second
//#define endl "\n"
#define int ll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

map<int, int> rec;

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    int nxt = 0;
    int cnt = 0;
    bool nw = true;
    int prev = 0;
    while(cin >> nxt){
        nw = !rec.count(nxt);
        if(rec.count(nxt)){
            prev = rec[nxt];
        }
        rec[nxt] = cnt;
        cin.ignore(1);
        cnt++;
    }
    for(; cnt < 2020; cnt++){
        if(nw){
            nw = !rec.count(0);
            if(rec.count(0)){
                prev = rec[0];
            }
            nxt = 0;
            rec[nxt] = cnt;   
        }else{
            nxt = cnt - prev - 1;
            nw = !rec.count(nxt);
            if(rec.count(nxt)){
                prev = rec[nxt];
            }
            rec[nxt] = cnt;
        }
    }
    cout << nxt << endl;
    return 0;
}



