#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T;
long long x;

set<long long> cubes;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    for(long long i = 1; i <= 10000; i++){
        cubes.insert(i*i*i);
    }
    while(T--){
        eat >> x;
        bool good = false;
        for(long long i = 1; i <= 10000; i++){
            long long dif = x - i*i*i;
            if(cubes.count(dif)){
                good = true;
                break;
            }
        }
        if(good) moo << "yEs" << endl;
        else moo << "nO" << endl;
    }
}
