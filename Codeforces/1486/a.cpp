#include <bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int T, N;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        int carry = 0;
        bool good = true;
        for(int i = 0; i < N; i++){
            int x; cin >> x;
            carry += x - i;
            good &= (carry >= 0);
        }
        cout << (good ? "yEs" : "no") << endl;
    }
}
