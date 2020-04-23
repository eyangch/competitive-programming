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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];       
        }
        set<int> nums;
        int minn = INT_MAX;
        int maxn = INT_MIN;
        for(int i = 0; i < n; i++){
            if(a[i] != -1 && ((i != 0 && a[i-1] == -1) || (i != n-1 && a[i+1] == -1))){
                minn = min(minn, a[i]);
                maxn = max(maxn, a[i]);
            }
        }
        int mdist = 0;
        for(int i = 0; i < n-1; i++){
            if(a[i] != -1 && a[i+1] != -1){
                mdist = max(mdist, abs(a[i]-a[i+1]));
            }
        }
        int avg = (minn + maxn) / 2; 
        cout << max(mdist, max(avg - minn, maxn - avg)) << " " << avg << endl;
    }
    return 0;
}


