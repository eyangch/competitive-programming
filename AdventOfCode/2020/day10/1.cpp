#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"
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

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    int nxt;
    vi a;
    while(cin >> nxt){
        a.push_back(nxt);  
    }
    sort(a.begin(), a.end());
    int j1 = 0, j3 = 1;
    int prev = 0;
    for(int i : a){
        if(i - prev == 1) j1++;
        if(i - prev == 3) j3++;
        prev = i;
    }
    cout << j1 << " " << j3 << " " << j1 * j3 << endl;
    return 0;
}



