#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, A[100000], pfx[100001], add[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		for(int i = 0; i < N; i++) add[i] = 0;
		pfx[0] = 0;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			pfx[i] += A[i];
			pfx[i+1] = pfx[i];
			for(int j = 0; j < 61; j++){
				if(i - j < 0) break;
				int bt = (A[i] >> j) & 1;
				add[i-j] += bt;
			}
		}
		int ans = pfx[N-1] - N * K, hf = 0;
		for(int i = 0; i < N; i++){
			if(i > 60) continue;
			hf += (A[i] >> (i+1));
		}
		for(int i = 0; i < N; i++){
			int cur = hf;
			if(i > 0) cur += pfx[i-1] - i * K;
			ans = max(ans, cur);
			hf *= 2;
			hf += add[i];
			hf -= A[i];
		}
		moo << ans << endl;
	}
}