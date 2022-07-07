#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[1000000], d[3000002], M;
map<int, int> m;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
		m[A[i]]++;
	}
	for(pair<int, int> i : m){
		int v = i.first;
		int o = i.second;
		m[v]--;
		int gone = 0;
		for(pair<int, int> j : m){
			int v2 = j.first;
			if(v * v2 > 3000000){
				d[3000001] += o * (N-1 - gone);
				break;
			}
			int o2 = j.second;
			d[v*v2] += o * o2;
			gone += o2;
		}
		m[v]++;
	}
	for(int i = 3000000; i >= 0; i--){
		d[i] += d[i+1];
	}
	eat >> M;
	for(int i = 0; i < M; i++){
		int P; eat >> P;
		moo << d[P] << endl;
	}
}