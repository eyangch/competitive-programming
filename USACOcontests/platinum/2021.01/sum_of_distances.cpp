#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int K, N[50000], M[50000], I[50000];
vector<vector<int>> G[50000];
vector<int> E[50000], O[50000], occ[50000], pfx[50000], occB[50000], pfxB[50000];
int Cpfx[200000], Csfx[200000], Zpfx[200000], Zsfx[200000], Bpfx[200000], Bsfx[200000], BZpfx[200000], BZsfx[200000];

int inv(int x){
	int e = MOD - 2;
	int ret = 1;
	for(int i = 0; i < 32; i++){
		if((e >> i) & 1){
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
	}
	return ret;
}

int calc(int i, int a, int (&sfx)[200000], int (&pfx)[200000], int (&zsfx)[200000], int (&zpfx)[200000], int sub){
	int cur = 1;
	if(a == 1e15) return 0;
	cur = sfx[a];
	if(zsfx[a]) return 0;
	if(a >= sub){
		cur = cur * pfx[a-sub] % MOD;
		if(zpfx[a-sub]) return 0;
	}else if(i != 0){
		return 0;
	}
	return cur;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> K;
	int mxn = 0;
	fill(Cpfx, Cpfx+200000, 1);
	fill(Csfx, Csfx+200000, 1);
	fill(Bpfx, Bpfx+200000, 1);
	fill(Bsfx, Bsfx+200000, 1);
	for(int i = 0; i < K; i++){
		eat >> N[i] >> M[i];
		G[i].resize(N[i]);
		E[i].resize(N[i], 1e15);
		O[i].resize(N[i], 1e15);
		occ[i].resize(2*N[i], 0);
		pfx[i].resize(2*N[i], 0);
		occB[i].resize(2*N[i], 0);
		pfxB[i].resize(2*N[i], 0);
		mxn = max(mxn, N[i]);
		for(int j = 0; j < M[i]; j++){
			int u, v; eat >> u >> v;
			u--, v--;
			G[i][u].push_back(v);
			G[i][v].push_back(u);
		}
		queue<pair<int, int>> q;
		q.push({0, 0});
		while(!q.empty()){
			int v = q.front().first, d = q.front().second;
			q.pop();
			if(d%2){
				if(O[i][v] != 1e15) continue;
				O[i][v] = d;
			}else{
				if(E[i][v] != 1e15) continue;
				E[i][v] = d;
			}
			occ[i][d]++;
			if(O[i][v] != 1e15 && E[i][v] != 1e15){
				occB[i][d]++;
			}
			for(int j : G[i][v]){
				q.push({j, d+1});
			}
		}
		pfx[i][0] = occ[i][0];
		pfx[i][1] = occ[i][1];
		pfxB[i][0] = occB[i][0];
		for(int j = 2; j < 2*N[i]; j++){
			pfx[i][j] = (occ[i][j] + pfx[i][j-2]) % MOD;
		}
		for(int j = 1; j < 2*N[i]; j++){
			pfxB[i][j] = (occB[i][j] + pfxB[i][j-1]) % MOD;
		}
	}
	iota(I, I+K, 0);
	sort(I, I+K, [](int a, int b){
		return N[a] < N[b];
	});
	int s = 0;
	int pfxe = 1, pfxo = 1;
	int aze = 0, azo = 0;
	for(int i = 0; i < 2*mxn; i++){
		for(int t = s; t < K; t++){
			int j = I[t];
			if(2*N[j] <= i){
				s++;
				int lgo = 2*N[j]-1;
				int lge = 2*N[j]-2;
				if(lge % 2){
					swap(lgo, lge);
				}
				if(pfx[j][lgo] == 0){
					azo++;
				}else{
					pfxo = pfxo * pfx[j][lgo] % MOD;
				}
				if(pfx[j][lge] == 0){
					aze++;
				}else{
					pfxe = pfxe * pfx[j][lge] % MOD;
				}
			}else{
				if(pfx[j][i] == 0){
					Zsfx[i]++;
				}else{
					Csfx[i] = Csfx[i] * pfx[j][i] % MOD;
				}
			}
		}
		if(i % 2){
			Zsfx[i] += azo;
			Csfx[i] = Csfx[i] * pfxo % MOD;
		}else{
			Zsfx[i] += aze;
			Csfx[i] = Csfx[i] * pfxe % MOD;
		}
	}
	s = 0;
	pfxo = 1;
	azo = 0;
	for(int i = 0; i < 2*mxn; i++){
		for(int t = s; t < K; t++){
			int j = I[t];
			if(2*N[j] <= i){
				s++;
				int lgo = 2*N[j]-1;
				if(pfxB[j][lgo] == 0){
					azo++;
				}else{
					pfxo = pfxo * pfxB[j][lgo] % MOD;
				}
			}else{
				if(pfxB[j][i] == 0){
					BZsfx[i]++;
				}else{
					Bsfx[i] = Bsfx[i] * pfxB[j][i] % MOD;
				}
			}
		}
		BZsfx[i] += azo;
		Bsfx[i] = Bsfx[i] * pfxo % MOD;
	}
	sort(I, I+K, [](int a, int b){
		return N[a] > N[b];
	});
	int ans = 0;
	int xe = 0, xo = 0, xb = 0;
	for(int h = 0; h < K; h++){
		int i = I[h];
		for(int j = 0; j < 2*N[i]; j++){
			if(pfx[i][j] == 0){
				Zsfx[j]--;
				continue;
			}
			Csfx[j] = Csfx[j] * inv(pfx[i][j]) % MOD;
		}
		for(int j = 0; j < 2*N[i]; j++){
			if(pfxB[i][j] == 0){
				BZsfx[j]--;
				continue;
			}
			Bsfx[j] = Bsfx[j] * inv(pfxB[i][j]) % MOD;
		}
		for(int j = 0; j < N[i]; j++){
			int a = E[i][j], b = O[i][j];
			int cur = 1;
			if(a > b) swap(a, b);
			ans += a * calc(h, a, Csfx, Cpfx, Zsfx, Zpfx, 2) % MOD;
			ans += b * calc(h, b, Csfx, Cpfx, Zsfx, Zpfx, 2) % MOD;
			ans -= b * calc(h, b, Bsfx, Bpfx, BZsfx, BZpfx, 1) % MOD;
			ans %= MOD;
		}
		for(int j = 0; j < 2*N[i]; j++){
			if(pfx[i][j] == 0){
				Zpfx[j]++;
				continue;
			}
			Cpfx[j] = Cpfx[j] * pfx[i][j] % MOD;
		}
		for(int j = 0; j < 2*N[i]; j++){
			if(pfxB[i][j] == 0){
				BZpfx[j]++;
				continue;
			}
			Bpfx[j] = Bpfx[j] * pfxB[i][j] % MOD;
		}
	}
	moo << (ans % MOD + MOD) % MOD << endl;
}