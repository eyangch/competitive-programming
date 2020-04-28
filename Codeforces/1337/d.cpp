#include <bits/stdc++.h>

#define int long long

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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n[3]; cin >> n[0] >> n[1] >> n[2];
        vector<int> a[3];
        vector<int> ac[3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n[i]; j++){
                int x; cin >> x;
                a[i].push_back(x);
            }
            sort(a[i].begin(), a[i].end());
            ac[i] = a[i];
            reverse(ac[i].begin(), ac[i].end());
        }
        int m = LLONG_MAX;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(j == i) continue;
                for(int k = 0; k < 3; k++){
                    if(k == i || k == j) continue;
                    for(int l = 0; l < n[j]; l++){
                        int idx1 = lower_bound(a[i].begin(), a[i].end(), a[j][l]) - a[i].begin();
                        if(idx1 == n[i]){
                            continue;
                        }
                        int idx2 = lower_bound(ac[k].begin(), ac[k].end(), a[j][l], greater<int>()) - ac[k].begin();
                        if(idx2 == n[k]){
                            continue;
                        }
                        int x = a[i][idx1], y = a[j][l], z = ac[k][idx2];
                        m = min(m, (int)(powl(x - y, 2) + powl(y - z, 2) + powl(z - x, 2)));
                    }
                }
            }
        }
        cout << m << endl;
    }
    return 0;
}


