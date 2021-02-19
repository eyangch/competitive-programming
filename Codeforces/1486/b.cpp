#include <bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int T, N, x[1000], y[1000];

int32_t main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> x[i] >> y[i];
        }
        sort(x, x+N), sort(y, y+N);
        if(N % 2) cout << 1 << endl;
        else cout << (x[N/2] - x[N/2-1] + 1) * (y[N/2] - y[N/2-1] + 1) << endl;
    }
}
