#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        int N;
        string s;
        cin >> N >> s;
        string a, b;
        bool encounter = false;
        for(int i = 0; i < N; i++){
            if(encounter){
                a += '0';
                b += s[i];
                continue;
            }
            if(s[i] == '2'){
                a += '1';
                b += '1';
            }else if(s[i] == '0'){
                a += '0';
                b += '0';
            }else{
                a += '1';
                b += '0';
                encounter = true;
            }
        }
        cout << a << endl << b << endl;
    }
    return 0;
}
