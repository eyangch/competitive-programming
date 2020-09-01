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

double ret1 = 0, ret2 = 100;

double a[200000];

void posneg(int N, double mid){
    double mpos = 0, cpos = 0, mneg = 0, cneg = 0;
    for(int i = 0; i < N; i++){
        cpos += a[i] - mid;
        cneg -= a[i] - mid;
        mpos = max(mpos, cpos);
        mneg = max(mneg, cneg);
        cpos = max(cpos, 0.0);
        cneg = max(cneg, 0.0);
    }
    ret1 = mpos;
    ret2 = mneg;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    double lo = -10000, hi = 10000, mid = 0;
    while(abs(ret1 - ret2) > 1e-6){
        mid = (lo+hi)/2.0;
        posneg(N, mid);
        double diff = ret1 - ret2;
        if(diff > 0){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout << fixed << setprecision(15) << ret1 << endl;
    return 0;
}


