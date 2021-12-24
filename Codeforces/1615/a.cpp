#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, a[100];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        int sum = 0;
        for(int i = 0; i < N; i++){
            eat >> a[i];
            sum += a[i];
        }
        moo << (sum % N > 0) << endl;
    }
}
