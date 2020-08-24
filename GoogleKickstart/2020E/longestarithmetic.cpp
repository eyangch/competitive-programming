#include <bits/stdc++.h>

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
        int N; cin >> N;
        int a[N];
        for(int i = 0; i < N; i++){
            cin >> a[i];   
        }
        int cdiff = 0;
        int ptr = 0;
        int pptr = -1;
        int ans = 0;
        while(ptr < N-1){
            cdiff = a[ptr] - a[ptr+1]; 
            while(ptr < N-1 && a[ptr] - a[ptr+1] == cdiff){
                ptr++;
            }
            ans = max(ans, ptr - pptr);
            pptr = ptr - 1;
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}


