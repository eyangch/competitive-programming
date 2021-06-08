#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[100];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        int mx = 0, sum = 0;
        for(int i = 0; i < N; i++){
            eat >> a[i];
            sum += a[i], mx = max(mx, a[i]);
        }
        if(mx > sum/2 || sum & 1) moo << "T" << endl;
        else moo << "HL" << endl;
    }
}
