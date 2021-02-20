#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int T, N;
string s[300];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> s[i];
        }
        int xs = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                xs += (s[i][j] == 'X');
            }
        }
        for(int offset = 0; offset < 3; offset++){
            int cx = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    cx += (s[i][j] == 'X' && (i + j + offset) % 3 == 0);
                }
            }
            if(cx <= xs/3){
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        if(s[i][j] == '.') cout << '.';
                        else if((i + j + offset) % 3 == 0){
                            cout << 'O';
                        }else{
                            cout << 'X';
                        }
                    }
                    cout << endl;
                }
                break;
            }
        }
    }
}
