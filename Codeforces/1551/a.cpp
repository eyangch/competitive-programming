#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        int c1 = N/3, c2 = N/3;
        if(N % 3 == 1) c1++;
        if(N % 3 == 2) c2++;
        moo << c1 << " " << c2 << endl;
    }
}
