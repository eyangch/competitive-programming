#include <bits/stdc++.h>
#define f first
#define s second

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N, B; cin >> N >> B;
        int a[N];
        for(int i = 0; i < N; i++) cin >> a[i];
        sort(a, a+N);
        int cnt = 0;
        int sum = 0;
        for(; cnt < N; cnt++){
            sum += a[cnt];
            if(sum > B) break;   
        }
        cout << "Case #" << tc << ": " << cnt << endl;
    }
    return 0;
}


