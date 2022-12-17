#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, C[300005], X[40];
vector<int> G[40];
int dp1[1<<20];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 1; i <= N; i++){
		eat >> C[i];
		C[i]--;
	}
	for(int i = 0; i < M; i++){
		eat >> X[i];
	}
	C[0] = C[1];
	C[N+1] = C[N];
	N += 2;
	for(int i = 0; i < N-1; i++){
		int u = C[i], v = C[i+1];
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 0; i < M; i++){
		sort(G[i].begin(), G[i].end());
		G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
	}
	int m2 = M/2;
	fill(dp1, dp1+(1<<m2), -1e15);
	for(int i = 0; i < (1<<m2); i++){
		bool ok = 1;
		int val = 0;
		for(int j = 0; j < m2 && ok; j++){
			if((i>>j) & 1){
				val += X[j];
				for(int k : G[j]){
					if((i>>k) & 1){
						ok = 0;
						break;
					}
				}
			}
		}
		if(ok){
			//moo << bitset<5>(i) << ' ' << val << endl;
			dp1[i] = val;
		}
	}
	for(int i = 0; i < (1<<m2); i++){
		for(int j = 0; j < m2; j++){
			if((i>>j) & 1){
				dp1[i] = max(dp1[i], dp1[i^(1<<j)]);
			}
		}
	}
	int m3 = M - m2;
	int ans = 0;
	for(int i = 0; i < (1<<m3); i++){
		bool ok = 1;
		int val = 0;
		for(int j = 0; j < m3 && ok; j++){
			if((i>>j) & 1){
				int adjj = j+m2;
				val += X[adjj];
				for(int k : G[adjj]){
					int adjk = k-m2;
					if(adjk < 0) continue;
					if((i>>adjk) & 1){
						ok = 0;
						break;
					}
				}
			}
		}
		if(!ok) continue;
		int i2 = (1<<m2)-1;
		for(int j = 0; j < m3; j++){
			if((i>>j) & 1){
				int adjj = j+m2;
				//moo << "J: " << adjj << endl;
				for(int k : G[adjj]){
					//moo << "K: " << k << endl;
					if(k >= m2) continue;
					if((i2>>k) & 1){
						i2 ^= (1<<k);
					}
				}
			}
		}
		//moo << bitset<5>(i) << ' ' << bitset<5>(i2) << ' ' << val << ' ' << dp1[i2] << endl;
		int cans = val + dp1[i2];
		ans = max(ans, cans);
	}
	//moo << ans << endl;
	ans = accumulate(X, X+M, 0) - ans;
	moo << ans << endl;
}