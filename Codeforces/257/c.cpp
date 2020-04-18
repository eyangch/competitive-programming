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

double getAngle(pii x){
    double raw = acos(x.first / sqrt(pow(x.first, 2) + pow(x.second, 2)));
    raw *= 180 / 3.1415926535897932384626;
    if(x.second < 0){
        raw = 180 - raw;
        raw += 180;
    }
    return raw;
}

int main(){
    cout.precision(16);
    int n; cin >> n;
    pii a[n];
    double angles[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;    
        angles[i] = getAngle(a[i]);
    }
    sort(angles, angles + n);
    double ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans = max(ans, angles[i + 1] - angles[i]);
    }
    ans = max(ans, angles[0] + 360 - angles[n - 1]);
    cout << 360 - ans << endl;
    return 0;
}


