#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    int m2 = -1;
    int fnd = -1;
    int occ = 0;
    for(int i = 0; i < N; i++){
        int x; eat >> x; x &= 1;
        if(m2 == -1) m2 = x;
        else if(m2 != x){
            fnd = i, occ++;
        }
    }
    moo << (occ == 1 ? fnd+1 : 1) << endl;
}
