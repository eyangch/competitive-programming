#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, A[3];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> A[0] >> A[1] >> A[2];
        sort(A, A+3);
        if(A[0] + A[1] == A[2]){
            moo << "YES" << endl;
        }else if(A[0] == A[1] && A[2] % 2 == 0){
            moo << "YES" << endl;
        }else if(A[1] == A[2] && A[0] % 2 == 0){
            moo << "YES" << endl;
        }else{
            moo << "NO" << endl;
        }
    }
}
