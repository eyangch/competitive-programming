#include <bits/stdc++.h>

using namespace std;

int main(){
    string board[8];
    bool done[8][8];
    fill(done[0], done[7] + 8, false);
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }
    int strokes = 0;
    for(int i = 0; i < 8; i++){
        bool horz = true;
        for(int j = 0; j < 8; j++){
            if(board[i][j] != 'B'){
                horz = false;
            }
        }
        if(horz){
            for(int j = 0; j < 8; j++){
                done[i][j] = true;
            }
        }
        strokes += horz;
    }
    for(int i = 0; i < 8; i++){
        bool vert = true;
        for(int j = 0; j < 8; j++){
            if(board[j][i] != 'B'){
                vert = false;
            }
        }
        int multiplier = 0;
        if(vert){
            for(int j = 0; j < 8; j++){
                if(done[j][i] == false){
                    multiplier = 1;
                }
            }
        }
        strokes += vert * multiplier;
    }
    cout << strokes << endl;
}
