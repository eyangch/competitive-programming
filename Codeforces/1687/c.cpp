#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, A[200000], B[200000], P[200000];
int pf2[200001];
pair<int, int> S[200000];
int Z[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		P[0] = 0;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		for(int i = 0; i < N; i++){
			eat >> B[i];
		}
		for(int i = 0; i < N; i++){
			P[i+1] = A[i] - B[i] + P[i];
		}
		/*for(int i = 0; i <= N; i++){
			moo << P[i] << '/' << A[i] - B[i] << ' ';
		}
		moo << endl;*/
		fill(Z, Z+M, 0);
		fill(pf2, pf2+N+1, 0);
		set<pair<int, pair<int, int>>> X;
		queue<int> Q;
		for(int i = 0; i < M; i++){
			int l, r; eat >> l >> r;
			l--, r--;
			pf2[l]++, pf2[r+1]--;
			if(P[l] == 0) Z[i] |= 1;
			if(P[r+1] == 0) Z[i] |= 2;
			S[i] = {l, r+1};
			if(Z[i] == 3){
				Q.push(i);
				continue;
			}
			X.insert({l, {i, 1}});
			X.insert({r+1, {i, 2}});
		}
		int cnt = 0;
		bool fl = 1;
		for(int i = 0; i < N; i++){
			cnt += pf2[i];
			if(cnt == 0 && A[i] != B[i]){
				fl = 0;
				break;
			}
		}
		if(!fl){
			moo << "No" << endl;
			continue;
		}
		while(!Q.empty()){
			int w = Q.front();
			//moo << "W" << w << endl;
			int l = S[w].first, r = S[w].second;
			Q.pop();
			auto it = X.lower_bound({l, {0, 0}});
			while(it != X.end() && it->first <= r){
				int j = it->second.first;
				int n = it->second.second;
				if(Z[j] != 3){
					Z[j] |= n;
					//moo << "P: " << Z[j] << endl;
					if(Z[j] == 3){
						Q.push(j);
					}
				}
				it = X.erase(it);
			}
		}
		if(X.empty()){
			moo << "YES" << endl;
		}else{
			/*for(auto it = X.begin(); it != X.end(); it++){
				moo << it->second.first << '/' << it->first << ' ';
			}*/
			moo << "NO" << endl;
		}
	}
}