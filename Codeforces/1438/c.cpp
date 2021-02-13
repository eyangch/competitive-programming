#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int T, N, M;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int x; cin >> x;
                if((i+j)%2 != x%2) x++;
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
