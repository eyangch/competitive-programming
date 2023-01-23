#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;

struct mint{
	int v;
	mint(){v = 0;}
	mint(int m){
		v = (m % MOD + MOD) % MOD;
	}
	mint inv(){
		mint xv(v);
		mint res(1);
		for(int i = 0; i < 32; i++){
			if((MOD-2)>>i & 1) res = res * xv;
			xv = xv * xv;
		}
		return res;
	}
	friend mint operator+(const mint &a, const mint &b){
		return (a.v + b.v) % MOD;
	}
	friend mint operator-(const mint &a, const mint &b){
		return (a.v - b.v + MOD) % MOD;
	}
	friend mint operator*(const mint &a, const mint &b){
		return (a.v * b.v) % MOD;
	}
};

int T, N, M, A[200002];
vector<vector<mint>> au, pau;

void init(vector<vector<mint>> &a){
	a.resize(N+2);
	for(int i = 0; i <= N+1; i++){
		a[i].resize(M+1);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		init(au), init(pau);
		A[0] = M+1;
		A[N+1] = M+1;
		for(int i = 1; i <= N; i++){
			eat >> A[i];
		}
		for(int i = 0; i <= M; i++){
			pau[0][i] = 1;
		}
		stack<pair<int, int>> av;
		av.push({A[0], 0});
		for(int i = 1; i <= N+1; i++){
			while(true){
				pair<int, int> x = av.top();
				if(x.first < A[i]){
					int a = av.top().second;
					av.pop();
					int b = av.top().second;
					int sum = 0;
					for(int j = 1; j <= M; j++){
						au[b][j] = pau[b][j-1] * pau[a][j];
					}
					for(int j = 1; j <= M; j++){
						pau[b][j] = (j == 1 ? 0 : pau[b][j-1]) + au[b][j];
					}
					pau[b][0] = 0;
				}else{
					break;
				}
			}
			for(int j = 0; j <= M; j++){
				pau[i][j] = 1;
			}
			av.push({A[i], i});
		}
		moo << pau[0][M].v << endl;
	}
}