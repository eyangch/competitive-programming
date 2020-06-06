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
    int n, l, r, ql, qr; cin >> n >> l >> r >> ql >> qr;
    int w[n];
    for(int i = 0; i < n; i++){
        cin >> w[i];   
    }
    int pfxL[n], pfxR[n];
    int qL[n], qR[n];
    pfxL[0] = w[0] * l;
    pfxR[n-1] = w[n-1] * r;
    qL[0] = 0;
    qR[n-1] = 0;
    for(int i = 1; i < n; i++){
        pfxL[i] = pfxL[i-1] + w[i] * l;
        qL[i] = ql * max(0, (i+1) - (n-i));
        pfxR[n-i-1] = pfxR[n-i] + w[n-i-1] * r;
        qR[n-i-1] = qr * max(0, (i+1) - (n-i));
    }
    //for(int i : pfxL) cout << i << endl;
    //cout << endl;
    //for(int i : pfxR) cout << i << endl;
    //for(int i = 0; i < n; i++) cout << qL[i] << " " << qR[i] << endl;
    int ans = min(pfxR[0] + qR[0], pfxL[n-1] + qL[n-1]);
    for(int i = 1; i < n; i++){
        ans = min(ans, pfxL[i-1] + pfxR[i] + qL[i-1] + qR[i]);
    }
    cout << ans << endl;
    return 0;
}


