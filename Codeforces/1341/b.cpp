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
        int n, k; cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool peak[n];
        peak[0] = peak[n-1] = false;
        for(int i = 1; i < n-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                peak[i] = true;
            }else{
                peak[i] = false;
            }
        }
        int maxt = 0;
        int l = 1;
        int pk = 0;
        for(int i = 1; i < k - 1; i++){
            pk += peak[i];
        }
        for(int i = 1; i + k - 1 <= n; i++){
            if(pk > maxt){
                maxt = pk;
                l = i;
            }
            pk += peak[i + k - 2];
            pk -= peak[i];
        }
        if(pk > maxt){
            maxt = pk;
            l = n - (k - 2);
        }
        cout << maxt + 1 << " " << l << endl;
    }
    return 0;
}


