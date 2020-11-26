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

int N, M, K;
int a[200000], b[200000];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }
    sort(a, a+N);
    sort(b, b+M);
    int aN = 0, bN = 0;
    int ans = 0;
    while(bN < M){
        while(aN < N && a[aN] + K < b[bN]){
            aN++;
        }
        if(aN >= N){
            break;
        }
        if(a[aN] - K <= b[bN]){
            ans++;
            aN++;
        }
        bN++;
    }
    cout << ans << endl;
    return 0;
}


