#include <bits/stdc++.h>
#define bignumber 1000001

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
    bool sieve[bignumber];
    fill(sieve, sieve + bignumber, true);
    for(int i = 2; i < bignumber; i++){
        if(sieve[i]){
            for(int j = 2 * i; j < bignumber; j += i){
                sieve[j] = false;
            }
        }
    }
    sieve[0] = sieve[1] = false;
    set<ll> primesquares;
    for(ll i = 0; i < bignumber; i++){
        if(sieve[i]){
            primesquares.insert(i * i);
        }
    }
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(primesquares.find(x) != primesquares.end()){
            cout << "YES" << endl;    
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


