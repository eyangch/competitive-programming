#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, L, N;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    for(int tc = 1; tc <= T; tc++){
        moo << "Case #" << tc << ": ";
        eat >> L >> N;
        int laps = 0, pos = 0, dir = -1;
        for(int i = 0; i < N; i++){
            char c;
            int d;
            eat >> d >> c;
            if(pos == 0){
                if(c == 'C') dir = 0;
                else dir = 1;
            }
            if(c == 'C'){
                pos += d;
                if(dir == 0){
                    laps += pos / L;
                }else{
                    laps += max(0LL, pos / L - 1);
                }
                if(pos >= L) dir = 0;
                pos %= L;
            }else{
                if(pos == 0) pos += L;
                pos -= d;
                int npos = L-pos;
                //moo << "NPOS: " << npos << endl;
                if(dir == 1){
                    laps += npos / L;
                }else{
                    laps += max(0LL, npos / L - 1);
                }
                if(pos <= 0) dir = 1;
                pos = (pos % L + L) % L;
            }
            //moo << laps << endl;
        }
        moo << laps << endl;
    }
}