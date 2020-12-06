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

signed main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int ans = 0;
    string rg;
    while(cin >> rg){
        string chr; cin >> chr;
        string pass; cin >> pass;
        int colon = 0;
        for(; colon < (int)rg.size(); colon++){
            if(rg[colon] == '-') break;
        }
        int n1 = stoi(rg.substr(0, colon));
        int n2 = stoi(rg.substr(colon+1));
        int cnt = 0;
        bool x1 = (pass[n1-1] == chr[0]);
        bool x2 = (pass[n2-1] == chr[0]);
        ans += x1^x2;
    }
    cout << ans << endl;
    return 0;
}



