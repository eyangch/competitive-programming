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
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int N;
int x[200000];
set<int> pre;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    int ans = INT_MIN;
    for(int i = 0; i < N; i++){
        cin >> x[i];
        if(i > 0){
            x[i] += x[i-1];
        }
        ans = max(ans, x[i]);
        ans = max(ans, x[i] - *pre.begin());
        pre.insert(x[i]);
    }
    cout << ans << endl;
    return 0;
}


