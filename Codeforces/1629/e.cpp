#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[1000][1000];
bool U[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int adj(int x, int y){
	int ret = 0;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= N || ny >= N){
			continue;
		}
		ret += U[nx][ny];
	}
	return ret;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				eat >> A[i][j];
				U[i][j] = 0;
			}
		}
		int ans = 0;
		for(int i = 1; i < N; i++){
			for(int j = 0; j < N; j++){
				if(!(adj(i-1, j) & 1)){
					U[i][j] = 1;
					ans ^= A[i][j];
				}
			}
		}
		moo << ans << endl;
	}
}