#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll binsrch(ll N, ll s[200000], ll t, ll top){
    ll l = 0;
    ll h = top;
    while(l < h){
        ll m = (l + h) / 2;
        if(s[m] + t > 0){
            h = m-1;
        }else{
            l = m+1;
        }
    }
    ll ret = l;
    while(s[ret] + t <= 0 && ret < N){
        ret++;
    }
    return ret;
}

int main(){
    ll N;
    cin >> N;
    ll a[N], b[N], s[200000];
    for(ll i = 0; i < N; i++) cin >> a[i];
    for(ll i = 0; i < N; i++) cin >> b[i];
    for(ll i = 0; i < N; i++) s[i] = a[i] - b[i];
    sort(s, s + N);
    ll ret = 0, top = N;
    for(ll i = 0; i < N; i++){
        ll x = binsrch(N, s, s[i], top);
        ret += N - x;
        if(x <= i) ret--;
        top = x;
    }
    cout << ret / 2 << endl;
    return 0;
}
