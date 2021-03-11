#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    for(int tc = 1; tc <= T; tc++){
        moo << "Case #" << tc << ": ";
        eat >> s;
        int d = 0;
        for(char i : s){
            int x = i - '0';
            while(d < x){
                moo << '(';
                d++;
            }
            while(d > x){
                moo << ')';
                d--;
            }
            moo << x;
        }
        while(d > 0){
            moo << ')';
            d--;
        }
        moo << endl;
    }
}
