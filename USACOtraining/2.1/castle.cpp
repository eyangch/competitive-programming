#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

array<array<array<bool, 4>, 50>, 50> wallsorig;
array<array<array<bool, 4>, 50>, 50> walls; // West, North, East, South
array<array<bool, 50>, 50> visited;

int total = 0;

void decodewall(int x, int y, int &n, int c, int index){
    if(n >= c){
        walls[x][y][index] = true;
        n -= c;
    }
}

void cvt(int y, int x, int n){
    visited[x][y] = false;
    for(int i = 0; i < 4; i++){
        walls[x][y][i] = false;
    }
    decodewall(x, y, n, 8, 3);
    decodewall(x, y, n, 4, 2);
    decodewall(x, y, n, 2, 1);
    decodewall(x, y, n, 1, 0);
}

int recur(int x, int y, int capx, int capy){
    if(visited[x][y] || x < 0 || y < 0 || x >= capx || y >= capy){
        return 0;
    }
    visited[x][y] = true;
    int num = 1;
    for(int i = 0; i < 4; i++){
        int dx = 0, dy = 0;
        if(i == 0)
            dx = -1;
        if(i == 1)
            dy = -1;
        if(i == 2)
            dx = 1;
        if(i == 3)
            dy = 1;
        if(!walls[x][y][i])
            num += recur(x + dx, y + dy, capx, capy);
    }
    return num;
}

void rstvisits(int M, int N){
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            visited[i][j] = false;
}

int main(){
    ifstream fin ("castle.in");
    ofstream fout ("castle.out");
    int M, N;
    fin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int num;
            fin >> num;
            cvt(i, j, num);
        }
    }

    wallsorig = walls;

    int lroom = 0;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                total++;
                lroom = max(lroom, recur(i, j, M, N));
            }
        }
    }
    fout << total << endl;
    fout << lroom << endl;
    rstvisits(M, N);

    int combinedroom = 0;

    vector<int> optimalx;
    vector<int> optimaly;
    vector<bool> optimalN;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 4; k++){
                if(walls[j][i][k]){
                    walls[j][i][k] = false;
                    int adjroom = recur(j, i, M, N);
                    if(adjroom >= combinedroom){
                        if(adjroom > combinedroom){
                            optimalx.clear();
                            optimaly.clear();
                            optimalN.clear();
                        }
                        combinedroom = adjroom;
                        if(k == 0){
                            optimaly.push_back(i);
                            optimalx.push_back(j + 1);
                            optimalN.push_back(false);
                        }
                        if(k == 1){
                            optimaly.push_back(i + 1);
                            optimalx.push_back(j + 1);
                            optimalN.push_back(true);
                        }
                        if(k == 2){
                            optimaly.push_back(i + 1);
                            optimalx.push_back(j + 1);
                            optimalN.push_back(false);
                        }
                        if(k == 3){
                            optimaly.push_back(i + 1);
                            optimalx.push_back(j + 2);
                            optimalN.push_back(true);
                        }
                    }
                    walls = wallsorig;
                    rstvisits(M, N);
                }
            }
        }
    }

    int top = 51;
    vector<int> topindex;

    for(unsigned int i = 0; i < optimalx.size(); i++){
        if(optimalx[i] <= top){
            if(optimalx[i] < top)
                topindex.clear();
            top = optimalx[i];
            topindex.push_back(i);
        }
    }

    top = 0;
    int topi = 0;

    for(int i : topindex){
        if(optimaly[i] > top){
            top = optimaly[i];
            topi = i;
        }
    }

    char direction = 'N';
    if(!optimalN[topi])
        direction = 'E';

    fout << combinedroom << endl << optimaly[topi] << " " << optimalx[topi] << " " << direction << endl;

    return 0;
}
