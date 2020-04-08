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

bool bckpii(pii a, pii b){
    return (a.second < b.second);
}

int main(){
    int n; cin >> n;
    pii a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    copy(a, a + n, b);
    sort(a, a + n);
    sort(b, b + n, bckpii);
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout << "Poor Alex" << endl;
    return 0;
}


