#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        int N, c[100];
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> c[i];
        }
        bool good = true;
        for(int i = 0; i < N-1; i++){
            if(c[i] % 2 != c[i+1] % 2){
                good = false;
                break;
            }
        }
        if(good){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
