#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K, C[100000], P[100000], A[100000], B[100000], I[100000], rI[100000];
int D0[100000], D1[100000], D2[100000], AD0[100000], AD1[100000];

struct segment_tree{
	pair<int, int> X[400005];
	void upd(int i, pair<int, int> x, int vl=0, int vr=99999, int v=1){
		if(vr < i || vl > i) return;
		if(vl == vr){
			X[v] = x;
		}else{
			upd(i, x, vl, (vl+vr)/2, v*2);
			upd(i, x, (vl+vr)/2+1, vr, v*2+1);
			X[v] = max(X[v*2], X[v*2+1]);
		}
	}
	int walk(int x, int vl=0, int vr=99999, int v=1){
		if(X[v].first < x || A[I[vl]] > x){
			return -1;
		}
		if(vl == vr){
			int ret = X[v].second;
			X[v] = {-1, -1};
			return ret;
		}
		int a = walk(x, vl, (vl+vr)/2, v*2);
		X[v] = max(X[v*2], X[v*2+1]);
		if(~a){
			return a;
		}
		int b = walk(x, (vl+vr)/2+1, vr, v*2+1);
		X[v] = max(X[v*2], X[v*2+1]);
		return b;
	}
};

segment_tree S1, S2, S3;

void dijkstra(int (&D)[100000], int (&AD)[100000], segment_tree &S){
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < N; i++){
		pq.push({-D[i], i});
	}
	while(!pq.empty()){
		int d = -pq.top().first, v = pq.top().second;
		pq.pop();
		if(d != D[v]) continue;
		while(true){
			int i = S.walk(v);
			if(i == -1) break;
			int td = d + P[i];
			AD[i] = d;
			if(td < D[C[i]]){
				D[C[i]] = td;
				pq.push({-td, C[i]});
			}
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	for(int i = 0; i < K; i++){
		eat >> C[i] >> P[i] >> A[i] >> B[i];
		C[i]--, A[i]--, B[i]--;
	}
	iota(I, I+K, 0);
	sort(I, I+K, [](int a, int b){
		return A[a] < A[b];
	});
	for(int i = 0; i < K; i++){
		int j = I[i];
		rI[j] = i;
		S1.upd(i, {B[j], j});
	}
	S2 = S1;
	S3 = S1;
	fill(D0, D0+N, 1e15);
	fill(AD0, AD0+N, 1e15);
	D0[0] = 0;
	dijkstra(D0, AD0, S1);
	fill(D1, D1+N, 1e15);
	fill(AD1, AD1+N, 1e15);
	D1[N-1] = 0;
	dijkstra(D1, AD1, S2);
	for(int i = 0; i < N; i++){
		D2[i] = D0[i] + D1[i];
	}
	for(int i = 0; i < K; i++){
		D2[C[i]] = min(D2[C[i]], AD0[i] + AD1[i] + P[i]);
	}
	dijkstra(D2, AD0, S3);
	for(int i = 0; i < N; i++){
		moo << (D2[i] > 1e14 ? -1 : D2[i]) << endl;
	}
}