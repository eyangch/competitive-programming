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
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int N, B; cin >> N >> B;
    int depth[N];
    set<pii> dset;
    for(int i = 0; i < N; i++){
        cin >> depth[i]; 
        dset.insert(pii(depth[i], i));  
    }
    pair<pii, int> boots[B];
    for(int i = 0; i < B; i++){
        cin >> boots[i].first.first >> boots[i].first.second;
        boots[i].second = i;
    }
    sort(boots, boots+B, greater<pair<pii, int>>());
    pii link[N];
    for(int i = 0; i < N; i++){
        link[i] = pii(i-1, i+1);
    }
    link[0].first = 0;
    link[N-1].second = N-1;
    bool ans[B];
    int maxgap = 1;
    for(int i = 0; i < B; i++){
        int d = boots[i].first.first, stride = boots[i].first.second;
        auto it = dset.upper_bound(pii(d, INT_MAX));
        for(; it != dset.end(); it++){
            int idx = (*it).second;
            int lidx = link[idx].first, ridx = link[idx].second;
            maxgap = max(maxgap, ridx - lidx);
            link[lidx].second = ridx;
            link[ridx].first = lidx;
        }
        it = dset.upper_bound(pii(d, INT_MAX));
        dset.erase(it, dset.end());
        ans[boots[i].second] = 0;
        if(stride >= maxgap){
            ans[boots[i].second] = 1;
        }
    }
    for(int i = 0; i < B; i++){
        cout << ans[i] << endl;
    }
    return 0;
}


