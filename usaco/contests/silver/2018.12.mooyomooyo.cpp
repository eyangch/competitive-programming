#include <bits/stdc++.h>

using namespace std;

array<array<bool, 10>, 100> visited;

vector<pair<int, int>> flood(int N, array<string, 100> board, int x, int y){
    vector<pair<int, int>> ret;
    if(visited[y][x])
        return ret;
    visited[y][x] = true;
    if(x < 9 && board[y][x] == board[y][x+1]){
        vector<pair<int, int>> tmp = flood(N, board, x+1, y);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
    }
    if(x > 0 && board[y][x] == board[y][x-1]){
        vector<pair<int, int>> tmp = flood(N, board, x-1, y);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
    }
    if(y < N-1 && board[y][x] == board[y+1][x]){
        vector<pair<int, int>> tmp = flood(N, board, x, y+1);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
    }
    if(y > 0 && board[y][x] == board[y-1][x]){
        vector<pair<int, int>> tmp = flood(N, board, x, y-1);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
    }
    ret.push_back(make_pair(x, y));
    return ret;
}

int main(){
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");
    int N, K;
    fin >> N >> K;
    array<string, 100> board;
    for(int i = 0; i < N; i++)
        fin >> board[i];
    bool done = false;
    while(!done){
        fill(visited[0].begin(), visited[N-1].end(), false);
        done = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 10; j++){
                if(visited[i][j] || board[i][j] == '0')
                    continue;
                vector<pair<int, int>> f = flood(N, board, j, i);
                if((int)f.size() >= K){
                    for(pair<int, int> k : f){
                        done = false;
                        board[get<1>(k)][get<0>(k)] = '0';
                    }
                }
            }
        }
        for(int i = 0; i < 10; i++){
            int mDown = 0;
            for(int j = N-1; j >= 0; j--){
                if(board[j][i] == '0')
                    mDown++;
                else
                    swap(board[j][i], board[j + mDown][i]);
            }
        }
    }
    for(int i = 0; i < N; i++)
        fout << board[i] << endl;
    return 0;
}
