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
        int a = N/3, b = N/3, c = N/3;
        if(a + b + c == N){
            moo << a << ' ' << b+1 << ' ' << c-1 << endl;
        }else if(a+b+c == N-1){
            moo << a << ' ' << b+2 << ' ' << c-1 << endl;
        }else{
            moo << a+1 << ' ' << b+2 << ' ' << c-1 << endl;
        }
    }
}
