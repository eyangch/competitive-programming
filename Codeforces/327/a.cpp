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
    int n; cin >> n;
    int a[n], b = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) a[i] = -1;
        else b++;  
    }
    int rc[n];
    rc[0] = -a[0];
    for(int i = 1; i < n; i++){
        rc[i] = rc[i-1] - a[i];
    }
    int m = -1;
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            m = max(m, rc[j] - rc[i]);
        }
    }
    for(int i = 0; i < n; i++){
        m = max(m, rc[i]);
    }
    cout << b + m << endl;
    return 0;
}


