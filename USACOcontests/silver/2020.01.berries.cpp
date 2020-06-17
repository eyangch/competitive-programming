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

ll n, k;
ll b[1000];
ll bcurr[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout); 
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b, b+n, greater<int>());
    ll fans = 0;
    for(ll v = 1; v <= 1000; v++){
        ll bucketn = 0;
        for(int i = 0; i < n; i++){
            bucketn += b[i] / v;
        }
        if(bucketn >= k){
            fans = max(fans, v * k/2);
            continue;
        }
        for(int i = 0; i < n; i++){
            bcurr[i] = b[i] % v;   
        }
        sort(bcurr, bcurr+n, greater<int>());
        ll ans = 0;
        for(int i = 0; i < k-bucketn; i++){
            ans += bcurr[i];
        }
        ans += (bucketn - k/2) * v;
        fans = max(ans, fans);
    }
    cout << fans << endl;
    return 0;
}


