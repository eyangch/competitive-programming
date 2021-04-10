#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, sieve[2000000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    int ans = 0;
    int x = 0;
    for(int i = 2; i * i <= N; i++){
        int cur = 0;
        while(N % i == 0){
            N /= i;
            cur++;
        }
        if(cur > ans){
            ans = cur;
            x = i;
        }
    }
    if(N > 1 && ans == 0) x = N;
    moo << x << endl;
}
