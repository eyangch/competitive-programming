#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, s[200000], f[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) eat >> s[i];
        for(int i = 0; i < N; i++) eat >> f[i];
        int ft = 0;
        for(int i = 0; i < N; i++){
            if(s[i] > ft) ft = s[i];
            moo << f[i] - ft << ' ';
            ft = f[i];
        }
        moo << endl;
    }
}
