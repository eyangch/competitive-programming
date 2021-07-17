#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[200000];

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
        int x = sum % N;
        moo << x * (N-x) << endl;
    }
}
