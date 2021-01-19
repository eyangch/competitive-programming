#include <bits/stdc++.h>

using namespace std;

int T;
int N;
string b;

int32_t main(){
    cin >> T;
    while(T--){
        cin >> N >> b;
        char prev = '0';
        for(int i = 0; i < N; i++){
            int plus = 1;
            if(b[i] + plus == prev){
                plus = 0;
            }
            prev = b[i] + plus;
            cout << plus;
        }
        cout << endl;
    }
}
