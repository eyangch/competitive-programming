#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

mt19937 rng(1234569420);
#define Z 4
#define Y (1<<16)
//#define Y (1<<3)

int N, M, K;
int B[151][1001][Z];
int cnt[Z][151][Y];
int tupd[Z][151][1001], tpt[Z][151];
int q1[Z][151], q2[Z][151];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M >> K;
	N++, M++;
	for(int i = 0; i < K; i++){
		int X1, Y1, X2, Y2;
		eat >> X1 >> Y1 >> X2 >> Y2;
		for(int j = 0; j < Z; j++){
			int hash = uniform_int_distribution<int>(0, Y-1)(rng);
			B[X1][Y1][j] ^= hash;
			B[X2][Y2][j] ^= hash;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < Z; k++){
				if(i) B[i][j][k] ^= B[i-1][j][k];
				if(j) B[i][j][k] ^= B[i][j-1][k];
				if(i && j) B[i][j][k] ^= B[i-1][j-1][k];
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int n = 0; n < i; n++){
			for(int z = 0; z < Z; z++){
				while(tpt[z][n] > 0){
					cnt[z][n][tupd[z][n][--tpt[z][n]]]--;
				}
				q1[z][n] = -1;
				q2[z][n] = 0;
			}
		}
		for(int j = 0; j < M; j++){
			for(int n = 0; n < i; n++){
				for(int z = 0; z < Z; z++){
					int k = q1[z][n];
					if(~k){
						cnt[z][n][k]++;
						tupd[z][n][tpt[z][n]++] = k;
					}
					q1[z][n] = q2[z][n];
				}
			}
			for(int k = 0; k < i; k++){
				int add = 1e9;
				for(int z = 0; z < Z; z++){
					int cur = B[i][j][z];
					if(k) cur ^= B[k-1][j][z];
					q2[z][k] = cur;
					add = min(add, cnt[z][k][cur]);
				}
				ans += add;
			}
		}
	}
	moo << ans << endl;
}