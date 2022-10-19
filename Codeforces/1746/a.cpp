#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, A[50];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		bool f1 = 0;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			if(A[i] == 1) f1 = 1;
		}
		if(!f1){
			moo << "NO" << endl;
			continue;
		}
		moo << "YES" << endl;
	}
}