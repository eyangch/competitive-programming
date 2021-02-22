#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int T, a, b;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> a >> b;
        if(a > b) swap(a, b);
        int ans = 0;
        for(int i = 1; a < b || (a - b) % 2; i++){
            a += i;
            ans = i;
        }
        cout << ans << endl;
    }
}
