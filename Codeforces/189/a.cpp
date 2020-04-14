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
    int n, a[3]; cin >> n >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int ans = 0;
    for(int i = n / a[0]; i >= 0; i--){
        int cn = n - a[0] * i;
        for(int j = cn / a[1]; j >= 0; j--){
            int cn2 = cn - a[1] * j;
            if(cn2 % a[2] == 0){
                ans = max(ans, i + j + (cn2 / a[2]));
            }
        }
    }
    cout << ans << endl;
    return 0;
}


