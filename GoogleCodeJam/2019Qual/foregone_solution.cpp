#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T;
string N;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    for(int tc = 1; tc <= T; tc++){
        moo << "Case #" << tc << ": ";
        eat >> N;
        string n1 = "", n2 = "";
        for(char i : N){
            if(i == '4'){
                n1 += '2';
                n2 += '2';
            }else{
                if(n2.size()){
                    n2 += '0';
                }
                n1 += i;
            }
        }
        moo << n1 << " " << n2 << endl;
    }
}
