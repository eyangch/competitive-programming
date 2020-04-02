#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    ll a[N], b[M];
    multiset<ll> accA, accB;
    ll curr1 = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] == 1){
            curr1++;
        }else if(curr1 != 0){
            accA.insert(curr1);
            curr1 = 0;
        }
    }
    if(curr1 != 0){
        accA.insert(curr1);
        curr1 = 0;
    }
    for(int i = 0; i < M; i++){
        cin >> b[i];
        if(b[i] == 1){
            curr1++;
        }else if(curr1 != 0){
            accB.insert(curr1);
            curr1 = 0;
        }
    }
    if(curr1 != 0){
        accB.insert(curr1);
        curr1 = 0;
    }
    vector<ll> factors;
    for(ll i = 1; i <= (ll)sqrt(K); i++){
        if(K % i == 0) factors.push_back(i);
    }
    ll ans = 0;
    for(int i : factors){
        int facafind = 0;
        multiset<ll>::iterator curr = accA.lower_bound(i);
        for(; curr != accA.end(); curr++){
            facafind += (*curr) - (i - 1);
        }
        int facbfind = 0;
        curr = accB.lower_bound(K / i);
        for(; curr != accB.end(); curr++){
            facbfind += (*curr) - (K / i - 1);
        }
        ans += facafind * facbfind;
        if(i != K / i){
            facafind = 0;
            curr = accA.lower_bound(K / i);
            for(; curr != accA.end(); curr++){
                facafind += (*curr) - (K / i - 1);
            }
            int facbfind = 0;
            curr = accB.lower_bound(i);
            for(; curr != accB.end(); curr++){
                facbfind += (*curr) - (i - 1);
            }
            ans += facafind * facbfind;
        }
    }
    cout << ans << endl;
    return 0;
}
