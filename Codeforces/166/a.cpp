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
    int n, k; cin >> n >> k;
    k--;
    pii pt[n];
    for(int i = 0; i < n; i++){
        cin >> pt[i].first >> pt[i].second;  
        pt[i].first = 50 - pt[i].first;  
    }
    sort(pt, pt + n);
    cout << upper_bound(pt, pt + n, pt[k]) - lower_bound(pt, pt + n, pt[k]) << endl;    
    return 0;
}


