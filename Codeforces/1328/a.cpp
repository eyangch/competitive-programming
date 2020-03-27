#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        int a, b;
        cin >> a >> b;
        if(a % b == 0) cout << 0 << endl;
        else cout << (a/b+1) * (b) - a << endl;
    }
    return 0;
}
