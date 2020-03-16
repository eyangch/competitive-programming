#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        if(s[s.length() - 1] == 'o'){
            cout << "FILIPINO" << endl;
        }
        if(s[s.length() - 1] == 'u'){
            cout << "JAPANESE" << endl;
        }
        if(s[s.length() - 1] == 'a'){
            cout << "KOREAN" << endl;
        }
    }
    return 0;
}
