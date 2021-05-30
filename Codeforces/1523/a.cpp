#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, M, d1[1000], d2[1000];
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M >> s;
        int prev = -1e9-5;
        for(int i = 0; i < N; i++){
            if(s[i] == '1') prev = i;
            d1[i] = i - prev;
        }
        prev = 1e9+1000000;
        for(int i = N-1; i >= 0; i--){
            if(s[i] == '1') prev = i;
            d2[i] = prev - i;
        }
        for(int i = 0; i < N; i++){
            if((d1[i] <= M || d2[i] <= M) && d1[i] != d2[i]) s[i] = '1';
        }
        moo << s << endl;
    }
}
