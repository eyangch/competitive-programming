#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, ans[100000];
string S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		eat >> S;
		fill(ans, ans+N, 0);
		int pvG = -1e15, pvH = -1e15;
		for(int i = 0; i < N; i++){
			if(S[i] == 'G'){
				if(i - pvG > K){
					int pt = i+K;
					if(pt >= N-1){
						pt = N-1;
						if(ans[N-1]){
							pt = N-2;
						}
					}
					ans[pt] = 1;
					pvG = pt;
				}
			}else{
				if(i - pvH > K){
					int pt = i+K;
					if(pt >= N-1){
						pt = N-1;
						if(ans[N-1]){
							pt = N-2;
						}
					}
					ans[pt] = 2;
					pvH = pt;
				}
			}
		}
		int ans1 = 0;
		for(int i = 0; i < N; i++){
			if(ans[i]) ans1++;
		}
		moo << ans1 << endl;
		for(int i = 0; i < N; i++){
			if(ans[i] == 0) moo << '.';
			if(ans[i] == 1) moo << 'G';
			if(ans[i] == 2) moo << 'H';
		}
		moo << endl;
	}
}