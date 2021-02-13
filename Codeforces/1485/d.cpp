#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        bool a = i%2;
        for(int j = 0; j < M; j++){
            int x; cin >> x;
            cout << 720720 - a*x*x*x*x << " ";
            a ^= 1;
        }
        cout << endl;
    }
}
