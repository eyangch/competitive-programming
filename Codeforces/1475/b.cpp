#include <bits/stdc++.h>

using namespace std;

int T;
int N;

int32_t main(){
    cin >> T;
    while(T--){
        cin >> N;
        bool y = false;
        for(int i = 0; i <= N; i+=2020){
            if((N - i) % 2021 == 0){
                y = true; break;
            }
        }
        cout << (y ? "YeS"  :"nO") << endl;
    }
}
