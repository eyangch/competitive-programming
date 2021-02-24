#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int T, N, p[100000], mx[100000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }
        mx[0] = 0;
        for(int i = 1; i < N; i++){
            mx[i] = mx[i-1];
            if(p[i] > p[mx[i]]){
                mx[i] = i;
            }
        }
        int ptr = N-1;
        while(ptr >= 0){
            for(int i = mx[ptr]; i <= ptr; i++){
                cout << p[i] << " ";
            }
            ptr = mx[ptr] - 1;
        }
        cout << endl;
    }
}
