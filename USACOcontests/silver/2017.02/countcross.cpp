#include <bits/stdc++.h>

using namespace std;

int N, K, R;
bool rVert[100][99], rHorz[99][100], cows[100][100], visited[100][100];

bool canPass(int r, int c, int r1, int c1){
    if(visited[r1][c1])
        return false;
    if(c == c1)
        return !rHorz[min(r, r1)][c];
    return !rVert[r][min(c, c1)];
}

int floodfill(int r, int c){
    int ret = cows[r][c];
    visited[r][c] = true;
    if(r > 0 && canPass(r, c, r-1, c))
        ret += floodfill(r-1, c);
    if(r < N-1 && canPass(r, c, r+1, c))
        ret += floodfill(r+1, c);
    if(c > 0 && canPass(r, c, r, c-1))
        ret += floodfill(r, c-1);
    if(c < N-1 && canPass(r, c, r, c+1))
        ret += floodfill(r, c+1);
    return ret;
}

int main(){
    ifstream fin("countcross.in");
	ofstream fout("countcross.out");
	fin >> N >> K >> R;
	fill(rVert[0], rVert[N-1] + N-1, false);
	fill(rHorz[0], rHorz[N-2] + N, false);
	fill(cows[0], cows[N-1] + N, false);
	fill(visited[0], visited[N-1] + N, false);
    for(int i = 0; i < R; i++){
        int r, c, r1, c1;
        fin >> r >> c >> r1 >> c1;
        r--;
        c--;
        r1--;
        c1--;
        if(c == c1)
            rHorz[min(r, r1)][c] = true;
        else
            rVert[r][min(c, c1)] = true;
    }
    for(int i = 0; i < K; i++){
        int r, c;
        fin >> r >> c;
        cows[r-1][c-1] = true;
    }
    vector<int> cowNumbers4EachBoxThing;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j]) continue;
            cowNumbers4EachBoxThing.push_back(floodfill(i, j));
        }
    }
    int ok = 0;
    for(int i : cowNumbers4EachBoxThing)
        ok += i * (K-i);
    ok /= 2;
    fout << ok << endl;
    return 0;
}
