#include <bits/stdc++.h>

using namespace std;

int T;
long long N;

int32_t main(){
    cin >> T;
    while(T--){
        cin >> N;
        bool y = false;
        long long p2 = 2;
        while(p2 < 1e14){
            if(N == p2){
                y = true; break;
            }
            p2 *= 2;
        }
        cout << (!y ? "YES" : "NO") << endl;
    }
}
