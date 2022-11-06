#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct sparse_table{
	int N, st[21][1000000], lg2[1000001];
	int GCD(int a, int b){
		if(b == 0) return a;
		return GCD(b, a % b);
	}
	void init(int N, int (&arr)[1000000]){
		for(int i = 0; i < N; i++){
			st[0][i] = arr[i];
		}
		this->N = N;
		lg2[1] = 0;
		for(int i = 2; i <= N; i++){
			lg2[i] = lg2[i/2] + 1;
		}
		for(int i = 1; i < 21; i++){
			for(int j = 0; j + (1<<i) <= N; j++){
				st[i][j] = GCD(st[i-1][j], st[i-1][j+(1<<(i-1))]);
			}
		}
	}
	int qry(int l, int r){
		if(l == r) return st[0][l];
		int lg = lg2[r - l + 1];
		return GCD(st[lg][l], st[lg][r-(1<<(lg))+1]);
	}
};

int N, K, H[1000000], pfx[1000000], nxt[1000000];
sparse_table S;

int sum(int l, int r){
	int ret = pfx[r];
	if(l > 0) ret -= pfx[l-1];
	return ret;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	for(int i = 0; i < N; i++){
		eat >> H[i];
	}
	pfx[0] = H[0];
	for(int i = 1; i < N; i++){
		pfx[i] = H[i] + pfx[i-1];
	}
	S.init(N, H);
	int ans = 0;
	set<int> loc;
	for(int i = N-1; i >= 0; i--){
		loc.insert(i);
		vector<int> rm;
		int pv = -1;
		for(auto it = loc.rbegin(); it != loc.rend(); it++){
			int j = *it;
			int cgcd = S.qry(i, j);
			if(cgcd == pv){
				rm.push_back(j);
				continue;
			}
			pv = cgcd;
			if(j >= i + K - 1) ans = max(ans, sum(i, j) * cgcd);
		}
		for(int j : rm){
			loc.erase(j);
		}
	}
	moo << ans << endl;
}