#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, P[1000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			eat >> P[i];
		}
		int tot = K;
		for(int i = 0; i < K; i++){
			if(P[i] <= K) tot--;
		}
		moo << tot << endl;
	}
}