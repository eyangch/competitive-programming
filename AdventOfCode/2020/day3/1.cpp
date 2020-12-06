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

vector<string> a;

ll check(int r, int d){
    ll ans = 0;
    int x = 0;
    for(int i = 0; i < (int)a.size(); i += d){
        ans += (a[i][x] == '#');
        x = (x + r) % (int)a[i].size();
    }
    return ans;
}

signed main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    string nxt;
    while(cin >> nxt){
        a.push_back(nxt);
    }
    ll ans = check(1, 1) * check(3, 1) * check(5, 1) * check(7, 1) * check(1, 2);
    cout << ans << endl;
    return 0;
}



