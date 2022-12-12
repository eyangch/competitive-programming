#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
vector<string> S;
int D[1000][1000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	string c;
	while(getline(eat, c)){
		if(c.size() == 0) break;
		S.push_back(c);
	}
	N = S.size();
	M = S[0].size();
	int sx, sy, ex, ey;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(S[i][j] == 'S'){
				sx = i, sy = j;
				S[i][j] = 'a';
			}
			if(S[i][j] == 'E'){
				ex = i, ey = j;
				S[i][j] = 'z';
			}
		}
	}
	queue<pair<int, int>> q;
	q.push({sx, sy});
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			D[i][j] = -1;
		}
	}
	D[sx][sy] = 0;
	auto chk = [](int a, int b){
		return (a >= 0 && b >= 0 && a < N && b < M);
	};
	while(!q.empty()){
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(!chk(nx, ny)) continue;
			if(~D[nx][ny]) continue;
			if(S[nx][ny] > S[cx][cy] + 1) continue;
			D[nx][ny] = D[cx][cy] + 1;
			q.push({nx, ny});
		}
	}
	/*for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			moo << D[i][j] << ' ';
		}
		moo << endl;
	}*/
	moo << D[ex][ey] << endl;
}