#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, S[1000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			eat >> S[i];
		}
		if(K * 2 < N){
			moo << "NO" << endl;
			continue;
		}
		map<int, int> m;
		bool ok = 1;
		for(int i = 0; i < N; i++){
			if(++m[S[i]] > 2){
				ok = 0;
				break;
			}
		}
		if(ok) moo << "YES" << endl;
		else moo << "NO" << endl;
	}
}