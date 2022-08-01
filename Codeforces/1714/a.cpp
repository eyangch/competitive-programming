#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, H, M, h[10], m[10];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> H >> M;
		for(int i = 0; i < N; i++){
			eat >> h[i] >> m[i];
		}
		int mins = 0;
		while(true){
			bool f = 0;
			for(int i = 0; i < N; i++){
				if(H == h[i] && M == m[i]){
					f = 1;
					break;
				}
			}
			if(f) break;
			M++;
			mins++;
			if(M == 60){
				M = 0;
				H++;
				if(H == 24) H = 0;
			}
		}
		moo << mins / 60 << ' ' << mins % 60 << endl;
	}
}