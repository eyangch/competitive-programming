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
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];        
    }
    ll sum[n];
    sum[0] = 0;
    for(int i = 0; i < k; i++){
        sum[0] += a[i];
    }
    for(int i = 1; i < n - k + 1; i++){
        sum[i] = sum[i-1];
        sum[i] -= a[i-1];
        sum[i] += a[i + k - 1];
    }
    priority_queue<pair<ll, ll>> pq;
    ll ans = 0;
    pii ansidx;
    for(int i = k; i < n - k + 1; i++){
        pq.push(make_pair(sum[i - k], n - (i - k)));
        ll curr = sum[i] + pq.top().first;
        if(curr > ans){
            ans = curr;
            ansidx = pii(n - pq.top().second, i);
        }
    }
    cout << ansidx.first + 1 << " " << ansidx.second + 1 << endl;
    return 0;
}


