#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[100001], r[100000];
string s;

void sub(int d){
    bool carry = 0;
    for(int i = N-1; i >= 0; i--){
        int c = d;
        if(carry) c--;
        carry = 0;
        if(c < a[i]){
            carry = 1;
            c += 10;
        }
        r[i] = c - a[i];
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> s;
        for(int i = 0; i < N; i++) a[i] = (s[i] - '0');
        a[N] = 0;
        if(a[0] == 9){
            sub(1);
        }else{
            sub(9);
        }
        for(int i = 0; i < N; i++) moo << r[i];
        moo << endl;
    }
}
