#include <bits/stdc++.h>
#define f first
#define s second

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

ll get(int x, ll (&BIT)[301000]){
    ll sum = 0;
    for(; x > 0; x -= x&-x){
        sum += BIT[x];
    }
    return sum;
}

void upd(int x, ll dv, int N, ll (&BIT)[301000]){
    for(; x <= N; x += x&-x){
        BIT[x] += dv;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    pii na[N];
    for(int i = 0; i < N; i++){
        na[i].s = i+1;
    }
    int ans = 0;
    ll invs = 0;
    ll BIT[301000];
    for(int i = 29; i >= 0; i--){
        int bt = (1<<i);
        for(int j = 0; j < N; j++){
            na[j].f += bt & a[na[j].s-1];
        }
        sort(na, na+N, greater<pii>());
        ll cinv[2];
        cinv[0] = cinv[1] = 0;
        for(int j = 0; j < 2; j++){
            stack<pii> ops;
            upd(na[0].s, 1, N, BIT);
            ops.push(pii(na[0].s, -1));
            for(int k = 1; k < N; k++){
                while(((na[k].f & (~bt)) != (na[k-1].f & (~bt))) && !ops.empty()){
                    upd(ops.top().f, ops.top().s, N, BIT);
                    ops.pop();
                }
                cinv[j] += get(na[k].s, BIT);
                upd(na[k].s, 1, N, BIT);
                ops.push(pii(na[k].s, -1));
            }
            while(!ops.empty()){
                upd(ops.top().f, ops.top().s, N, BIT);
                ops.pop();
            }
            if(j == 0){
                for(int k = 0; k < N; k++){
                    na[k].f ^= bt;
                }
                sort(na, na+N, greater<pii>());
            }
        }
        if(cinv[0] <= cinv[1]){
            invs += cinv[0];
        }else{
            invs += cinv[1];
            ans |= bt;
        }
    }
    cout << invs << " " << ans << endl;
    return 0;
}


