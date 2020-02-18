#include <bits/stdc++.h>

using namespace std;

int main(){
    string x[3];
    cin >> x[0] >> x[1] >> x[2];
    for(int i = 0; i < 3; i++){
        if(x[0][i] != x[2][2-i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i = 0; i < 3; i++){
        if(x[i][0] != x[2-i][2]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
