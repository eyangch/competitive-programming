#include <bits/stdc++.h>

using namespace std;

void setAvailable(bool (&available)[100][100], bool been[100][100], bool light[100][100], queue<pair<int, int>> &qr, int x, int y, int N){
    if(x > 0)
        available[x-1][y] = !been[x-1][y];
    if(x < N-1)
        available[x+1][y] = !been[x+1][y];
    if(y > 0)
        available[x][y-1] = !been[x][y-1];
    if(y < N-1)
        available[x][y+1] = !been[x][y+1];
    if(x < N-1 && available[x+1][y] && light[x+1][y])
        qr.push(make_pair(x+1, y));
    if(x > 0 && available[x-1][y] && light[x-1][y])
        qr.push(make_pair(x-1, y));
    if(y < N-1 && available[x][y+1] && light[x][y+1])
        qr.push(make_pair(x, y+1));
    if(y > 0 && available[x][y-1] && light[x][y-1])
        qr.push(make_pair(x, y-1));
}

int main(){
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    int N, M, ret = 0;
    fin >> N >> M;
    vector<pair<int, int>> rooms[N][N];
    bool lightRooms[100][100], availableRooms[100][100], been[100][100];
    fill(lightRooms[0], lightRooms[N-1] + N, false);
    fill(availableRooms[0], availableRooms[N-1] + N, false);
    fill(been[0], been[N-1] + N, false);
    lightRooms[0][0] = true;
    for(int i = 0; i < M; i++){
        int a1, a2, b1, b2;
        fin >> a1 >> a2 >> b1 >> b2;
        rooms[a1-1][a2-1].push_back(make_pair(b1-1, b2-1));
    }
    queue<pair<int, int>> qrooms;
    qrooms.push(make_pair(0, 0));
    while(!qrooms.empty()){
        pair<int, int> croom = qrooms.front();
        qrooms.pop();
        if(been[croom.first][croom.second])
            continue;
        vector<pair<int, int>> switches = rooms[croom.first][croom.second];
        been[croom.first][croom.second] = true;
        availableRooms[croom.first][croom.second] = false;
        setAvailable(availableRooms, been, lightRooms, qrooms, croom.first, croom.second, N);
        for(pair<int, int> i : switches){
            lightRooms[i.first][i.second] = true;
            if(availableRooms[i.first][i.second])
                qrooms.push(i);
        }
    }
    for(int i = 0; i< N; i++)
        for(int j= 0; j < N; j++)
            if(lightRooms[i][j])
                ret++;
    fout << ret << endl;
    return 0;
}
