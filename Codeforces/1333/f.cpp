#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, lf[500001];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 2; i <= N; i++){
        if(lf[i]) continue;
        for(int j = i; j <= N; j += i){
            if(!lf[j]) lf[j] = j/i;
        }
    }
    sort(lf, lf+N+1);
    for(int i = 2; i <= N; i++){
        moo << lf[i] << " ";
    }
    moo << endl;
}
