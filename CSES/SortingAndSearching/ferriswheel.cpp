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

int N, X;
set<pii> p;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        p.insert(pii(a, i));
    }
    int use2 = 0;
    for(auto it = p.begin(); it != p.end(); it++){
        pii pi = (*it);
        auto find = p.upper_bound(pii(X - pi.f, 1e9));
        if(find == p.begin()){
            break;
        }
        find--;
        pii match = *find;
        if(match <= pi){
            break;
        }
        use2++;
        p.erase(find);
    }
    cout << use2 + (N - use2 * 2) << endl;
    return 0;
}


