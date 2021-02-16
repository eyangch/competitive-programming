#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int T, N;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        cout << ((int)sqrt(2 * N - 1)-1)/2 << endl;
    }
}
