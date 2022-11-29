#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[500000], uwu[500000];
vector<int> pf[500005], pr[500005];
int prptr[500005];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 2; i <= N; i++){
		if(pf[i].size()) continue;
		for(int j = i; j <= N; j += i){
			pf[j].push_back(i);
		}
	}
	for(int i = 0; i < N; i++){
		eat >> A[i];
		for(int j : pf[A[i]]){
			if(pr[j].size()){
				uwu[i]++;
			}
			pr[j].push_back(i);
		}
	}
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < N; i++){
		if(uwu[i] == 0){
			pq.push({A[i], i});
		}
	}
	vector<int> ans;
	while(!pq.empty()){
		int val = pq.top().first;
		int i = pq.top().second;
		pq.pop();
		ans.push_back(val);
		for(int j : pf[val]){
			prptr[j]++;
			if(prptr[j] == pr[j].size()) continue;
			int k = pr[j][prptr[j]];
			uwu[k]--;
			if(uwu[k] == 0){
				pq.push({A[k], k});
			}
		}
	}
	assert(ans.size() == N);
	for(int i : ans){
		moo << i << ' ';
	}
	moo << endl;
}