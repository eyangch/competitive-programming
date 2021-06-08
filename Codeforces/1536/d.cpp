#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, b[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> b[i];
        }
        set<int> s;
        s.insert(b[0]);
        int prev = b[0];
        bool good = true;
        for(int i = 1; i < N; i++){
            auto it = s.insert(b[i]).first;
            bool ok = false;
            if((*it) == prev) ok = true;
            if(it != s.begin()){
                it--;
                if((*it) == prev){
                    ok = true;
                }
                it++;
            }
            it++;
            if(it != s.end()){
                if((*it) == prev){
                    ok = true;
                }
            }
            if(!ok){
                good = false;
                break;
            }
            prev = b[i];
        }
        if(good) moo << "yEs" << endl;
        else moo << "nO" << endl;
    }
}
