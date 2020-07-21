#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll T, A, B; 

bool lessThan(pii a, pii b){
    return (A * a.first + B * a.second) > (A * b.first + B * b.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin >> T >> A >> B;
    T *= 2;
    bool am2 = A%2, bm2 = B%2;
    pii kp[2 * T+2];
    fill(kp, kp+2*T+2, pii(INT_MAX, INT_MAX));
    kp[0] = pii(0, 0);
    for(int i = 0; i <= 2*T; i++){
        if(kp[i] == pii(INT_MAX, INT_MAX)){
            continue;
        }
        if(i + 2 * A <= T+1 && lessThan(kp[i + 2 * A], kp[i])){
            if(i+2*A != T+1 || am2 * kp[i].first + bm2 * kp[i].second > 0){
                kp[i+2*A] = kp[i];
            }
        }
        if(i + 2 * B <= T+1 && lessThan(kp[i + 2 * B], kp[i])){
            if(i+2*B != T+1 || am2 * kp[i].first + bm2 * kp[i].second > 0){
                kp[i+2*B] = kp[i];
            }
        }
        if(i + B <= T+1 && lessThan(kp[i + B], make_pair(kp[i].first, kp[i].second+1))){
            kp[i+B] = make_pair(kp[i].first, kp[i].second+1);
        }
        if(i + A <= T+1 && lessThan(kp[i + A], make_pair(kp[i].first+1, kp[i].second))){
            kp[i+A] = make_pair(kp[i].first+1, kp[i].second);
        }
    }
    for(int i = T+1; i >= 0; i--){
        if(A * kp[i].first + B * kp[i].second <= T/2){
            cout << i/2 << endl;
            break;
        }
    }
    return 0;
}


