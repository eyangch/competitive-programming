#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, m[100][100];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    for(int tc = 1; tc <= T; tc++){
        moo << "Case #" << tc << ": ";
        eat >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                eat >> m[i][j];
            }
        }
        int trace = 0;
        for(int i = 0; i < N; i++){
            trace += m[i][i];
        }
        int r = 0;
        for(int i = 0; i < N; i++){
            set<int> s;
            for(int j = 0; j < N; j++){
                if(s.count(m[i][j])){
                    r++;
                    break;
                }
                s.insert(m[i][j]);
            }
        }
        int c = 0;
        for(int i = 0; i < N; i++){
            set<int> s;
            for(int j = 0; j < N; j++){
                if(s.count(m[j][i])){
                    c++;
                    break;
                }
                s.insert(m[j][i]);
            }
        }
        moo << trace << " " << r << " " << c << endl;
    }
}
