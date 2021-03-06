#include <bits/stdc++.h>
#define endl "\n"
#define moo cout
#define int long long

using namespace std;

int N, K, a[500000];
bool ok = true;

int lis_bound(int l, int r, int lx, int rx){
    if(r - l + 1 > rx - lx){
        ok = false;
    }
    vector<int> lis;
    for(int i = l; i < r; i++){
        if(a[i] - (i - l) > lx && a[i] + (r - i) <= rx){
            auto it = lower_bound(lis.begin(), lis.end(), a[i] - (i - l));
            if(it == lis.end()) lis.push_back(a[i] - (i - l + 1));
            else lis[it-lis.begin()] = a[i] - (i - l + 1);
        }
    }
    return lis.size();
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int prev = 0, prevn = -1e10;
    int ans = 0;
    for(int i = 0; i < K; i++){
        int x; cin >> x;
        ans += lis_bound(prev, x-1, prevn, a[x-1]);
        prev = x;
        prevn = a[x-1];
    }
    ans += lis_bound(prev, N, prevn, 1e10);
    moo << (ok ? N - K - ans : -1) << endl;
}
