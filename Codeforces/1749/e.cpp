#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dx2[] = {-1, -1, 1, 1};
int dy2[] = {1, -1, -1, 1};
int T, N, M;
string S[200000];
vector<int> dp[200000], vis[200000], ord[200000];

bool ok(int x, int y){
	if(x < 0 || y < 0 || x >= N || y >= M) return 0;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= N || ny >= M){
			continue;
		}
		if(S[nx][ny] == '#') return 0;
	}
	return 1;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i < N; i++){
			eat >> S[i];
			dp[i].resize(M);
			vis[i].resize(M);
			ord[i].resize(M);
			fill(dp[i].begin(), dp[i].end(), 1e15);
			fill(vis[i].begin(), vis[i].end(), 0);
		}
		deque<pair<int, int>> dq;
		for(int i = 0; i < N; i++){
			if(!ok(i, 0)) continue;
			if(S[i][0] == '#'){
				dp[i][0] = 0;
				dq.push_front({i, 0});
			}else{
				dp[i][0] = 1;
				dq.push_back({i, 0});
			}
		}
		int cnt = 0;
		while(!dq.empty()){
			int x = dq.front().first, y = dq.front().second;
			dq.pop_front();
			if(vis[x][y]) continue;
			vis[x][y] = 1;
			ord[x][y] = cnt++;
			for(int i = 0; i < 4; i++){
				int nx = x + dx2[i], ny = y + dy2[i];
				if(!ok(nx, ny)) continue;
				int res = dp[x][y] + 1;
				if(S[nx][ny] == '#'){
					res--;
				}
				if(dp[nx][ny] > res){
					dp[nx][ny] = res;
					if(S[nx][ny] == '#'){
						dq.push_front({nx, ny});
					}else{
						dq.push_back({nx, ny});
					}
				}
			}
		}
		int ans = 1e15;
		int x = 0, y = M-1;
		for(int i = 0; i < N; i++){
			if(dp[i][M-1] < ans){
				ans = dp[i][M-1];
				x = i;
			}
		}
		if(ans > 1e10){
			moo << "NO" << endl;
			continue;
		}
		moo << "YES" << endl;
		while(1){
			int cur = dp[x][y];
			int sub = 1 - (S[x][y] == '#');
			S[x][y] = '#';
			if(y == 0) break;
			for(int i = 0; i < 4; i++){
				int nx = x + dx2[i], ny = y + dy2[i];
				if(!ok(nx, ny)) continue;
				if(ord[nx][ny] > ord[x][y]) continue;
				if(dp[nx][ny] == cur - sub){
					x = nx, y = ny;
					break;
				}
			}
		}
		for(int i = 0; i < N; i++){
			moo << S[i] << endl;
		}
	}
}