#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int T, R, C;
string S[3000];
int adj[3000][3000];

bool good(int x, int y){
	if(x >= 0 && y >= 0 && x < R && y < C && S[x][y] != '#') return true;
	return false;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> R >> C;
		for(int i = 0; i < R; i++){
			eat >> S[i];
		}
		queue<pair<int, int>> q;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(!good(i, j)) continue;
				int open = 0;
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k], ny = j + dy[k];
					if(!good(nx, ny)) continue;
					open++;
				}
				adj[i][j] = open;
				if(open < 2){
					q.push({i, j});
				}
			}
		}
		bool ok = 1;
		while(!q.empty()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			if(S[x][y] == '^'){
				ok = 0;
				break;
			}
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i], ny = y + dy[i];
				if(!good(nx, ny)) continue;
				adj[nx][ny]--;
				if(adj[nx][ny] == 1){
					q.push({nx, ny});
				}
			}
		}
		if(!ok){
			moo << "Impossible" << endl;
		}else{
			moo << "Possible" << endl;
			for(int i = 0; i < R; i++){
				for(int j = 0; j < C; j++){
					if(S[i][j] == '#') moo << '#';
					else if(adj[i][j] < 2) moo << '.';
					else moo << '^';
				}
				moo << endl;
			}
		}
	}
}