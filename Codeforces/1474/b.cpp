#include <bits/stdc++.h>
#define int long long

using namespace std;

int T;
bool sieve[500000];

int32_t main(){
    cin >> T;
    for(int i = 2; i < 500000; i++){
        if(sieve[i]) continue;
        for(int j = 2*i; j < 500000; j += i){
            sieve[j] = true;
        }
    }
    while(T--){
        int d; cin >> d;
        int ans = d+1;
        for(; sieve[ans]; ans++){}
        int x = ans + d;
        for(; sieve[x]; x++){}
        cout << ans * x << endl;
    }
}
