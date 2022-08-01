#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct edge{
	int v, a, b;
};

int T, N, ans[200000];
vector<edge> G[200000];
vector<int> bsum;

void dfs(int v, int sum){
	int len = upper_bound(bsum.begin(), bsum.end(), sum) - bsum.begin();
	ans[v] = len-1;
	for(edge e : G[v]){
		bsum.push_back(e.b + bsum.back());
		dfs(e.v, sum + e.a);
		bsum.pop_back();
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			G[i].clear();
		}
		bsum.clear();
		bsum.push_back(0);
		for(int i = 1; i < N; i++){
			int p, a, b; eat >> p >> a >> b;
			p--;
			G[p].push_back({i, a, b});
		}
		dfs(0, 0);
		for(int i = 1; i < N; i++){
			moo << ans[i] << ' ';
		}
		moo << endl;
	}
}