#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct edge{
	int d, s, e, i;
};

int T, N, K, A[1000000], B[1000000], X[1000000], Y[1000000], rc1[2000000], rc2[2000000];
int indeg[2000010];
map<int, int> cc1, cc2;
set<int> s1, s2;
vector<edge> G[2000000];
multiset<int> F[2000000];
multimap<int, int> H2[2000000];
multimap<int, int> H[2000000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		cc1.clear(), cc2.clear();
		s1.clear(), s2.clear();
		moo << "Case #" << tc << ": ";
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			F[i].clear();
			eat >> A[i] >> B[i] >> X[i] >> Y[i];
			s1.insert(A[i]);
			s1.insert(B[i]);
			s2.insert(X[i]);
			s2.insert(Y[i]);
		}
		auto it = s1.begin(), it2 = s2.begin();
		for(int i = 0; i < s1.size(); i++){
			G[i].clear();
			H[i].clear();
			F[i].clear();
			H2[i].clear();
			cc1[*it] = i;
			rc1[i] = *it;
			it++;
		}
		multiset<int> ans;
		for(int i = 0; i < K; i++){
			ans.insert(0);
		}
		fill(indeg, indeg+s1.size()+5, 0);
		queue<int> q;
		for(int i = 0; i < N; i++){
			int v = cc1[A[i]];
			int u = cc1[B[i]];
			indeg[u]++;
			F[i].insert(0);
			for(int j = 0; j < K-1; j++){
				F[i].insert(-999999999999999LL);
			}
			int s = X[i];
			int e = Y[i];
			H2[v].insert({s, i});
			G[v].push_back({u, s, e, i});
		}
		for(int i = 0; i < s1.size(); i++){
			multiset<int> mx;
			for(int j = 0; j < K; j++){
				mx.insert(-99999999999LL);
			}
			auto ptr = H2[i].begin();
			for(auto it = H[i].begin(); it != H[i].end(); it++){
				while(ptr != H2[i].end() && ptr -> first <= it -> first){
					for(int j : mx){
						int aj = j + ptr->first;
						if(*F[ptr->second].begin() < aj){
							F[ptr->second].erase(F[ptr->second].begin());
							F[ptr->second].insert(aj);
						}
					}
					ptr++;
				}
				int bid = it->second;
				for(int k : F[bid]){
					int ak = k - it->first;
					if(ak > *mx.begin()){
						mx.erase(mx.begin());
						mx.insert(ak);
					}
				}
			}
			while(ptr != H2[i].end()){
				for(int j : mx){
					int aj = j + ptr->first;
					if(*F[ptr->second].begin() < aj){
						F[ptr->second].insert(aj);
						F[ptr->second].erase(F[ptr->second].begin());
					}
				}
				ptr++;
			}
			for(edge e : G[i]){
				int d = e.d;
				int start = e.s;
				int end = e.e;
				int id = e.i;
				H[d].insert({end, id});
			}
		}
		for(int i = 0; i < N; i++){
			for(int j : F[i]){
				//moo << j << ' ';
				if(j > *ans.begin()){
					ans.erase(ans.begin());
					ans.insert(j);
				}
			}
			//moo << endl;
		}
		int ansn = 0;
		for(int i : ans){
			//moo << i << ' ';
			ansn += i;
		}
		moo << ansn % 1000000007 << endl;
	}
}