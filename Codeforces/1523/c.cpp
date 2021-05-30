#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, a[1000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        vector<int> cur;
        for(int i = 0; i < N; i++){
            if(a[i] == 1){
                cur.push_back(1);
            }else{
                while(cur.back() != a[i]-1) cur.pop_back();
                cur.back()++;
            }
            for(int j = 0; j < (int)cur.size(); j++){
                if(j != 0) moo << '.';
                moo << cur[j];
            }
            moo << endl;
        }
    }
}
