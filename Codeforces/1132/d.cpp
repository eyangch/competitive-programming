#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K;
int A[200000], B[200000], P[200000];

bool works(int x){
	fill(P, P+N, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 0; i < N; i++){
		pq.push({A[i]/B[i], i});
	}
	for(int i = 0; i < K-1; i++){
		int a = pq.top().second;
		pq.pop();
		P[a] += x;
		pq.push({(A[a]+P[a])/B[a], a});
		if(pq.top().first <= i){
			return false;
		}
	}
	return true;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	for(int i = 0; i < N; i++){
		eat >> B[i];
	}
	if(!works(1e13)){
		moo << -1 << endl;
		return 0;
	}
	int hi = 1;
	while(hi < 2e13 && !works(hi)) hi *= 10;
	int lo = hi/10, mid = 0, ans = -1;
	while(lo <= hi){
		mid = (lo + hi)/2;
		if(works(mid)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}
	moo << ans << endl;
}