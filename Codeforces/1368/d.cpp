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

ll bign;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    ll a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    ll b[64];
    fill(b, b+64, 0);
    for(int i = 0; i < N; i++){
        bitset<64> tmpb(a[i]);
        string cbs = tmpb.to_string();
        for(int j = 0; j < 64; j++){
            b[j] += (int)(cbs[j] - 48);
        }
    }
    ll ans = 0;
    while(true){
        ll curr = 0;
        for(int i = 0; i < 64; i++){
            curr += powl(2, 64-i-1) * min(1LL, b[i]);
            b[i]--;
            b[i] = max(b[i], 0LL);
        }
        ans += powl(curr, 2);
        bool stop = true;
        for(int i = 0; i < 64; i++){
            if(b[i] > 0){
                stop = false;
                break;
            }
        }
        if(stop){
            break;
        }
    }
    cout << ans << endl;
    return 0;
}


