#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, M;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        long long ans = (1LL<<(M-1))-1;
        int b = -1;
        set<long long> vis;
        for(int i = 0; i < N; i++){
            string s; eat >> s;
            long long x = stoll(s, 0, 2);
            vis.insert(x);
            if(x == ans){
                if(b == 0){
                    b = -1;
                    while(vis.count(--ans)){}
                }else{
                    b = 0;
                    while(vis.count(++ans)){}
                }
            }else if(x < ans){
                b--;
                if(b < -1){
                    b = 0;
                    while(vis.count(++ans)){}
                }
            }else{
                b++;
                if(b > 0){
                    b = -1;
                    while(vis.count(--ans)){}
                }
            }
        }
        moo << bitset<60>(ans).to_string().substr(60-M) << endl;
    }
}
