#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    char C;
    unordered_set<char> adj;
    cin >> N >> M >> C;
    string room[N];
    for(int i = 0; i < N; i++){
        cin >> room[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(room[i][j] == C){
                if(i > 0 && room[i-1][j] != '.' && room[i-1][j] != C){
                    adj.insert(room[i-1][j]);
                }
                if(i < N-1 && room[i+1][j] != '.' && room[i+1][j] != C){
                    adj.insert(room[i+1][j]);
                }
                if(j > 0 && room[i][j-1] != '.' && room[i][j-1] != C){
                    adj.insert(room[i][j-1]);
                }
                if(j < M-1 && room[i][j+1] != '.' && room[i][j+1] != C){
                    adj.insert(room[i][j+1]);
                }
            }
        }
    }
    cout << adj.size() << endl;
    return 0;
}
