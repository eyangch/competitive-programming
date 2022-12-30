#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, A[100000], M[100001];
vector<int> Q[100001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		//set<pair<int, int>> Q;
		eat >> N >> K;
		fill(M, M+100001, 0);
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		for(int i = 0; i < N; i++){
			int div = 1;
			int p = 1e15;
			while(div <= A[i]){
				M[A[i]/div] = max(M[A[i]/div], p);
				p = A[i]/div;
				div = A[i]/(A[i]/div)+1;
			}
			M[A[i]/div] = max(M[A[i]/div], p);
		}
		int ans = 1e15;
		int mx = *max_element(A, A+N) / K;
		for(int i = 0; i <= 100000; i++){
			ans = min(ans, mx - i);
			mx = max(mx, M[i]);
		}
		moo << ans << endl;
	}
}