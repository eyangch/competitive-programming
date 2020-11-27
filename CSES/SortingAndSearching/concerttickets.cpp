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

int N, M;
multiset<int> h;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M; 
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        h.insert(x);
    }
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        auto it = h.upper_bound(x);
        if(it == h.begin()){
            cout << -1 << endl;
            continue;
        }
        it--;
        cout << *it << endl;
        h.erase(it);
    }
    return 0;
}


