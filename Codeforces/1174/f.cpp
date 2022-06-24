#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N;
vector<int> graph[200000];
int sz[200000], sb[200000], dr;

int qd(int v){
	moo << "d " << v+1 << endl;
	moo.flush();
	int r; eat >> r;
	if(r == -1) exit(0);
	return r;
}

int qs(int v){
	moo << "s " << v+1 << endl;
	moo.flush();
	int r; eat >> r;
	if(r == -1) exit(0);
	return r-1;
}

int dfs_sz(int i, int p){
	sz[i] = 1;
	for(int c : graph[i]){
		if(c == p) continue;
		sz[i] += dfs_sz(c, i);
	}
	return sz[i];
}

int dfs_sb(int i, int p, int d){
	if(d == dr){
		sb[i] = 1;
		return sb[i];
	}
	for(int c : graph[i]){
		if(c == p) continue;
		sb[i] += dfs_sb(c, i, d+1);
	}
	return sb[i];
}

int dfs_td(int i, int t){
	if(sb[i] <= t/3) return -1;
	int ans = i;
	for(int c : graph[i]){
		if(sz[c] > sz[i]) continue;
		int x = dfs_td(c, t);
		if(x == -1) continue;
		if(sb[x] < sb[ans] || (sb[x] == sb[ans] && sz[x] < sz[ans])) ans = x;
	}
	return ans;
}

int calc_d(int i){
	int ret = 0;
	while(sb[i]){
		int ip = i;
		for(int c : graph[i]){
			if(sz[c] > sz[i]) continue;
			if(sb[c]) i = c;
		}
		if(i == ip){
			break;
		}
		ret++;
	}
	return ret;
}

int dfs_upd(int i, int t){
	if(i == t) return 0;
	int ret = 0;
	bool ed = true;
	for(int c : graph[i]){
		if(sz[c] > sz[i]) continue;
		if(c != t && sb[c] == 0) continue;
		ed = false;
		ret += dfs_upd(c, t);
	}
	if(!ed) sb[i] = ret;
	return sb[i];
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	dfs_sz(0, -1);
	dr = qd(0);
	dfs_sb(0, -1, 0);
	int r = 0;
	while(sb[r] > 1){
		int ct = sb[r];
		bool use_s = true;
		for(int i : graph[r]){
			if(sz[r] < sz[i]) continue;
			if(sb[i] >= 2 * sb[r] / 3){
				use_s = false;
				break;
			}
		}
		if(use_s){
			r = qs(r);
		}else{
			int v = dfs_td(r, sb[r]);
			int vd = qd(v);
			if(vd > calc_d(v)){
				sb[v] = 0;
				dfs_upd(r, v);
			}else{
				r = v;
			}
		}
	}
	while(true){
		bool op = false;
		for(int c : graph[r]){
			if(sz[c] > sz[r]) continue;
			if(sb[c]){
				op = 1;
				r = c;
				break;
			}
		}
		if(!op) break;
	}
	moo << "! " << r+1 << endl;
}