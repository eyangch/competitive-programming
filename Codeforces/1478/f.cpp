#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second

using namespace std;
typedef pair<long long, long long> pii;

int N;
pii a[5000];
int p[5000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i].fi >> a[i].se;
    }
    iota(p, p+N, 0);
    for(int i = 2; i < N; i++){
        for(int j = i; j >= 2; j--){
            pii v = a[p[j-1]], x = a[p[j]], y = a[p[j-2]];
            long long dot_p = (x.fi - v.fi) * (y.fi - v.fi) + (x.se - v.se) * (y.se - v.se);
            if(dot_p <= 0){
                swap(p[j], p[j-1]);
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << p[i]+1 << " ";
    }
    cout << endl;
}
