#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		if(K == 1){
			for(int i = 0; i < N; i++){
				moo << i+1 << ' ';
			}
			moo << endl;
		}else{
			int lb = 1;
			int cnt = 0;
			for(int i = N; i >= lb; i--){
				cnt++;
				//moo << lb << ' ' <<i << endl;
				if(cnt == K){
					moo << lb++ << ' ';
					cnt = 0;
					i++;
					//lb++;
				}else{
					moo << i << ' ';
				}
			}
			moo << endl;
		}
	}
}