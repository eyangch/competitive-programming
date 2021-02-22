#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int T, N, a[5000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        bool found = false;
        for(int i = 0; i < N; i++){
            for(int j = i+2; j < N; j++){
                if(a[i] == a[j]) found = true;
            }
        }
        cout << (found ? "yEs" : "nO") << endl;
    }
}
