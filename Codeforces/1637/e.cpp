#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, M, A[300000], cnt[300001];
int rcc[300000];
vector<int> sct[300001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i <= N; i++){
			cnt[i] = 0;
			vector<int>().swap(sct[i]);
		}
		set<int> sa;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			sa.insert(A[i]);
		}
		map<int, int> cc;
		K = sa.size();
		int ct = 0;
		for(int i : sa){
			cc[i] = ct;
			rcc[ct++] = i;
		}
		for(int i = 0; i < N; i++){
			cnt[cc[A[i]]]++;
		}
		vector<pair<int, int>> bad;
		for(int i = 0; i < M; i++){
			int x, y; eat >> x >> y;
			bad.push_back({cc[x], cc[y]});
			bad.push_back({cc[y], cc[x]});
		}
		sort(bad.begin(), bad.end());
		for(int i = 0; i < K; i++){
			sct[cnt[i]].push_back(i);
		}
		vector<int> avct;
		for(int i = 0; i <= N; i++){
			sort(sct[i].begin(), sct[i].end(), greater<int>());
			if(sct[i].size()){
				avct.push_back(i);
			}
		}
		int ans = 0;
		for(int i : avct){
			for(int j : avct){
				for(int k : sct[i]){
					int x = rcc[k];
					int cur = 0;
					for(int l : sct[j]){
						if(k != l && !binary_search(bad.begin(), bad.end(), pair<int, int>{k, l})){
							int y = rcc[l];
							ans = max(ans, (x + y) * (i + j));
							break;
						}
						cur++;
					}
					if(!cur) break;
				}
			}
		}
		moo << ans << endl; moo.flush();
	}
}