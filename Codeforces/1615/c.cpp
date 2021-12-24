#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N;
string a, b;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> a >> b;
        int z = 0, o = 0, bo = 0;
        for(int i = 0; i < N; i++){
            z += (a[i] == '0');
            o += (a[i] == '1');
            bo += (b[i] == '1');
        }
        int ans = 1e15;
        if(bo == o){
            int dif = 0;
            for(int i = 0; i < N; i++){
                if(a[i] != b[i]) dif++;
            }
            ans = min(ans, dif);
        }
        if(bo == z+1){
            int dif = 0;
            for(int i = 0; i < N; i++){
                if(a[i] == b[i]) dif++;
            }
            ans = min(ans, dif);
        }
        moo << (ans == 1e15 ? -1 : ans) << endl;
    }
}
