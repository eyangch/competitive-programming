#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T;
string N;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        set<int> even;
        even.insert('2');
        even.insert('4');
        even.insert('6');
        even.insert('8');
        if(even.count(N[N.size()-1])) moo << 0;
        else if(even.count(N[0])) moo << 1;
        else{
            bool good = 0;
            for(int i = 0; i < N.size(); i++){
                if(even.count(N[i])){
                    good = true;
                    break;
                }
            }
            if(good){
                moo << 2;
            }else moo << -1;
        }
        moo << endl;
    }
}
