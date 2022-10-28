#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N;
vector<int> G[100000];
bool fd = 0;

bool ok(vector<int> &v, int x, int skip){
	int l = 0, r = v.size()-1;
	if(skip == l) l++;
	if(skip == r) r--;
	while(l < r){
		if(v[l] + v[r] < x) return 0;
		l++, r--;
		if(l == skip) l++;
		if(r == skip) r--;
	}
	return 1;
}

int dfs(int v, int p, int x){
	vector<int> lv;
	for(int c : G[v]){
		if(c == p) continue;
		lv.push_back(dfs(c, v, x)+1);
	}
	if(lv.size() == 0) return 0;
	vector<int> lv0 = lv;
	if(lv0.size() % 2) lv0.push_back(0);
	sort(lv0.begin(), lv0.end());
	int res = -1e15;
	if(ok(lv0, x, 1e15)){
		res = 0;
		if(p == -1) return 0;
	}
	if(lv.size() % 2 == 0) lv.push_back(0);
	sort(lv.begin(), lv.end());
	int lo = 0, hi = lv.size()-1, mid = 0;
	while(lo <= hi){
		mid = (lo + hi) / 2;
		if(ok(lv, x, mid)){
			res = lv[mid];
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}
	return res;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("deleg.in", "r", stdin); freopen("deleg.out", "w", stdout);
	eat >> N;
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int lo = 1, hi = N, mid = 0, ans = -1;
	while(lo <= hi){
		mid = (lo + hi) / 2;
		int x = dfs(0, -1, mid);
		if(x >= mid || x == 0){
			ans = mid;
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}
	moo << ans << endl;
}