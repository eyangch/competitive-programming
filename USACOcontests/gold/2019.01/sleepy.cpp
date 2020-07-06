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

void upd(int N, ll (&bit)[120000], int idx){
    while(idx < N+1){
        bit[idx]++;
        idx += (idx & -idx);
    }
}

ll get(int N, ll (&bit)[120000], int idx){
    ll ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int N; cin >> N;
    ll a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int sorted = 1;
    ll bit[120000];
    fill(bit, bit+N, 0);
    upd(N, bit, a[N-1]);
    for(int i = N-1; i > 0; i--){
        if(a[i] > a[i-1]){
            sorted++;
            upd(N, bit, a[i-1]);
        }else{
            break;
        }
    }
    int ops = N-sorted;
    cout << ops << endl;
    for(int i = 0; i < ops; i++){
        int add = get(N, bit, a[i]);
        cout << ops - i + add - 1 << (i < ops-1 ? " " : "");
        upd(N, bit, a[i]);
    }
    cout << endl;
    return 0;
}


