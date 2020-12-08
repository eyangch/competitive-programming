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

int N, Q;
int a[100000];

signed main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a+N);
    for(int i = 0; i < Q; i++){
        int A, B; cin >> A >> B;
        cout << upper_bound(a, a+N, B) - lower_bound(a, a+N, A) << endl;
    }
    return 0;
}


