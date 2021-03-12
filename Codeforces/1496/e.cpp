#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, M;
string b[500];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++){
            eat >> b[i];
        }
        for(int i = (N % 3 == 0); i < N; i += 3){
            b[i] = string(M, 'X');
            if(i > 1){
                bool found = false;
                for(int j = 0; j < M; j++){
                    if(b[i-1][j] == 'X' || b[i-2][j] == 'X'){
                        b[i-1][j] = b[i-2][j] = 'X';
                        found = true;
                        break;
                    }
                }
                if(!found){
                    b[i-1][0] = b[i-2][0] = 'X';
                }
            }
        }
        for(int i = 0; i < N; i++){
            moo << b[i] << endl;
        }
    }
}
