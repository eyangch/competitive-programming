#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		if(M < N){
			moo << "NO" << endl;
			continue;
		}
		if(N % 2 == 0 && M % 2 == 1){
			moo << "No" << endl;
			continue;
		}
		moo << "YES" << endl;
		if(N % 2 == 1){
			for(int i = 0; i < N-1; i++){
				moo << 1 << ' ';
			}
			moo << M-(N-1) << endl;
		}else{
			for(int i = 0; i < N-2; i++){
				moo << 1 << ' ';
			}
			int x = M - (N-2);
			moo << x/2 << ' ' << x/2 << endl;
		}
	}
}