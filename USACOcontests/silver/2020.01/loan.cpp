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

ll N, K, M;

bool works(ll x){
    ll amount = N;
    ll days = K;
    while(amount > 0 && days > 0){
        ll Y = amount / x;
        if(Y <= M){
            amount -= days * M;
            break;
        }
        ll gap = amount - Y * x;
        gap /= Y;
        gap++;
        amount -= gap * Y;
        days -= gap;
    }
    if(amount <= 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin >> N >> K >> M;
    ll lo = 1;
    ll hi = 1e12;
    ll mid;
    while(lo < hi){
        mid = (lo+hi)/2;
        bool ok = works(mid), ok2 = works(mid+1);
        if(ok && !ok2){
            break;
        }else if(ok){
            lo = mid+1;        
        }else{
            hi = mid-1;
        }
    }
    while(works(mid)){
        mid++;
    }
    while(mid > 0 && !works(mid)){
        mid--;
    }
    cout << mid << endl;
    return 0;
}


