#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[500000], amx[250000], amn[250000], bmx[250000], bmn[250000];
int dp[250000];
vector<int> qx[250001], qn[250001];

struct segtree1{
	int N, a[1000000];
	void init(int N){
		this->N = N;
		fill(a, a+4*N, 1e9);
	}
	void upd(int i, int l, int r, int v, int x){
		if(l > r || l > v || r < v) return;
		if(l == r){
			a[i] = x;
		}else{
			upd(i*2, l, (l+r)/2, v, x);
			upd(i*2+1, (l+r)/2+1, r, v, x);
			a[i] = min(a[i*2], a[i*2+1]);
		}
	}
	int qry(int i, int l, int r, int ql, int qr){
		if(l > r || ql > r || qr < l) return 1e9;
		if(l >= ql && r <= qr){
			return a[i];
		}
		return min(qry(i*2, l, (l+r)/2, ql, qr), qry(i*2+1, (l+r)/2+1, r, ql, qr));
	}
};

segtree1 stmn, stmx;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> a[i];
		}
		fill(amx, amx+N, N);
		fill(amn, amn+N, N);
		fill(bmx, bmx+N, N);
		fill(bmn, bmn+N, N);
		set<pair<int, int>> s1;
		for(int i = 0; i < N; i++){
			for(auto it = s1.begin(); it != s1.end();){
				if(it->first > a[i]) break;
				amx[it->second] = i;
				it = s1.erase(it);
			}
			s1.insert({a[i], i});
		}
		set<pair<int, int>, greater<pair<int, int>>> s2;
		for(int i = 0; i < N; i++){
			for(auto it = s2.begin(); it != s2.end();){
				if(it->first < a[i]) break;
				amn[it->second] = i;
				it = s2.erase(it);
			}
			s2.insert({a[i], i});
		}
		s1.clear();
		s2.clear();
		for(int i = N-1; i >= 0; i--){
			for(auto it = s1.begin(); it != s1.end();){
				if(it->first > a[i]) break;
				bmx[it->second] = i;
				it = s1.erase(it);
			}
			s1.insert({a[i], i});
		}
		for(int i = N-1; i >= 0; i--){
			for(auto it = s2.begin(); it != s2.end();){
				if(it->first < a[i]) break;
				bmn[it->second] = i;
				it = s2.erase(it);
			}
			s2.insert({a[i], i});
		}
		fill(dp, dp+N, 1e9);
		dp[N-1] = 0;
		stmn.init(N);
		stmx.init(N);
		stmn.upd(1, 0, N-1, N-1, 0);
		stmx.upd(1, 0, N-1, N-1, 0);
		for(int i = 0; i < N; i++){
			qx[i].clear();
			qn[i].clear();
		}
		qx[bmx[N-1]].push_back(N-1);
		qn[bmn[N-1]].push_back(N-1);
		for(int i = N-2; i >= 0; i--){
			for(int j : qx[i]){
				stmx.upd(1, 0, N-1, j, 1e9);
			}
			for(int j : qn[i]){
				stmn.upd(1, 0, N-1, j, 1e9);
			}
			dp[i] = stmx.qry(1, 0, N-1, i, amn[i]);
			dp[i] = min(dp[i], stmn.qry(1, 0, N-1, i, amx[i]));
			dp[i]++;
			stmx.upd(1, 0, N-1, i, dp[i]);
			stmn.upd(1, 0, N-1, i, dp[i]);
			qx[bmx[i]].push_back(i);
			qn[bmn[i]].push_back(i);
		}
		moo << dp[0] << endl;
	}
}