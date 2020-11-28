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

int N;
int sieve[1000001];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 2; i < 1000001; i++){
        if(sieve[i]) continue;
        for(int j = 1; i * j < 1000001; j++){
            sieve[i * j] = i;
        }
    }
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        int ans = 1;
        while(x > 1){
            int mp = 0;
            int p = sieve[x];
            while(x % p == 0){
                x /= p;
                mp++;
            }
            ans *= mp+1;
        }
        cout << ans << endl;
    }
    return 0;
}


