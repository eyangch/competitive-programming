#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct fest{
	int t, x, y;
};

int N, M, T, K, C[50], A[30][50][5][50][5], H[50][5], P[50][5];
vector<int> G[50][5];
fest F[201];

void mx(int &x, int y){
	x = max(x, y);
}

void add(int bit){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 5; j++){
			P[i][j] = H[i][j];
			H[i][j] = -1e14;
		}
		P[i][0] -= C[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < N; k++){
				for(int l = 0; l < 5; l++){
					mx(H[k][l], P[i][j] + A[bit][i][j][k][l]);
				}
			}
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M >> T >> K;
	for(int i = 0; i < N; i++){
		eat >> C[i];
	}
	for(int i = 0; i < M; i++){
		int u, v, w;
		eat >> u >> v >> w;
		u--, v--, w--;
		G[u][w].push_back(v);
	}
	for(int i = 0; i < 30; i++){
		for(int j = 0; j < 50; j++){
			for(int k = 0; k < 5; k++){
				for(int l = 0; l < 50; l++){
					for(int m = 0; m < 5; m++){
						A[i][j][k][l][m] = -1e14;
					}
				}
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int k : G[i][0]){
			mx(A[0][i][0][k][0], C[i] + C[k]);
		}
		mx(A[0][i][0][i][1], C[i]);
		for(int j = 1; j < 5; j++){
			for(int k : G[i][j]){
				mx(A[0][i][j][k][0], C[k]);
			}
			if(j < 4){
				mx(A[0][i][j][i][j+1], 0);
			}
		}
	}
	for(int i = 1; i < 30; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < 5; k++){
				for(int l = 0; l < N; l++){
					for(int m = 0; m < 5; m++){
						int cd1 = A[i-1][j][k][l][m];
						if(cd1 < 0) continue;
						for(int n = 0; n < N; n++){
							for(int o = 0; o < 5; o++){
								int cd2 = A[i-1][l][m][n][o];
								if(cd2 < 0) continue;
								if(m == 0) cd2 -= C[l];
								mx(A[i][j][k][n][o], cd1 + cd2);
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < K; i++){
		eat >> F[i].t >> F[i].x >> F[i].y;
		F[i].x--;
	}
	F[K] = {T, 0, 0};
	sort(F, F+K+1, [](fest a, fest b){
		return a.t < b.t;
	});
	int pv = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 5; j++){
			H[i][j] = -1e14;
		}
	}
	H[0][0] = C[0];
	for(int i = 0; i < K+1; i++){
		int dis = F[i].t - pv;
		for(int j = 0; j < 30; j++){
			if((dis >> j) & 1){
				add(j);
			}
		}
		H[F[i].x][0] += F[i].y;
		pv = F[i].t;
	}
	moo << (H[0][0] < 0 ? -1 : H[0][0]) << endl;
}