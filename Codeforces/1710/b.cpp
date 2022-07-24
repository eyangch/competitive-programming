#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, I[200000];
pair<int, int> P[200000];
bool ans[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		fill(ans, ans+N, 0);
		//bit.init(N);
		for(int i = 0; i < N; i++){
			eat >> P[i].first >> P[i].second;
		}
		iota(I, I+N, 0);
		sort(I, I+N, [](int a, int b){
			return P[a].first < P[b].first;
		});
		vector<int> add, sub;
		for(int i = 0; i < N; i++){
			add.push_back(P[i].first - P[i].second);
			sub.push_back(P[i].first);
			add.push_back(P[i].first + P[i].second);
		}
		sort(add.begin(), add.end());
		sort(sub.begin(), sub.end());
		int aptr = 0, sptr = 0;
		int dy = 0, cur = 0;
		set<pair<int, int>> af, pv;
		for(int i = 0; i < N; i++){
			af.insert({P[i].second - P[i].first, i});
		}
		for(int i1 = 0; i1 < N; i1++){
			int i = I[i1];
			int mp = 0;
			if(i1 > 0){
				mp = P[i].first - P[I[i1-1]].first;
			}
			cur += dy * mp;
			while(aptr < (int)add.size() && add[aptr] < P[i].first){
				dy++;
				cur += P[i].first - add[aptr];
				aptr++;
			}
			while(sptr < (int)sub.size() && sub[sptr] < P[i].first){
				dy -= 2;
				cur -= 2 * (P[i].first - sub[sptr]);
				sptr++;
			}
			vector<pair<int, int>> rm;
			if(cur > M){
				for(pair<int, int> j : af){
					if(cur - (j.first + P[i].first) <= M) break;
					rm.push_back(j);
				}
				for(pair<int, int> j : rm){
					af.erase(j);
				}
				rm.clear();
				for(pair<int, int> j : pv){
					if(cur - (j.first - P[i].first) <= M) break;
					rm.push_back(j);
				}
				for(pair<int, int> j : rm){
					pv.erase(j);
				}
				rm.clear();
			}
			pair<int, int> old = {P[i].second - P[i].first, i};
			pair<int, int> nw = {P[i].second + P[i].first, i};
			if(af.count(old)){
				af.erase(old);
				pv.insert(nw);	
			}
		}
		for(pair<int, int> j : pv){
			ans[j.second] = 1;
		}
		for(int i = 0; i < N; i++){
			moo << ans[i];
		}
		moo << endl;
	}
}