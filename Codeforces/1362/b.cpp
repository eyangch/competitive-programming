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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        bool exist[1024];
        fill(exist, exist + 1024, false);
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            exist[a[i]] = true;   
        }
        int ans = -1;
        for(int i = 1; i < 1024; i++){
            bool currexist[1024];
            copy(exist, exist + 1024, currexist);
            for(int j = 0; j < n; j++){
                currexist[a[j] ^ i] = false;
            }
            bool good = true;
            for(int j = 0; j < 1024; j++){
                if(currexist[j]){
                    good = false;
                    break;
                }
            }
            if(good){
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


