#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, C[100000], nxt[100000], pv[100000], ans[100000];
bool vis[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		fill(nxt, nxt+N, -1);
		fill(pv, pv+N, -1);
		fill(vis, vis+N, 0);
		fill(ans, ans+N, 0);
		for(int i = 0; i < N; i++){
			eat >> C[i];
			C[i]--;
			if(~pv[C[i]]){
				nxt[pv[C[i]]] = i;
			}
			pv[C[i]] = i;
		}
		for(int i = 0; i < N; i++){
			if(vis[i]) continue;
			int ptr = i;
			int cpv = i+1;
			while(true){
				if(ptr % 2 != cpv % 2){
					ans[C[ptr]]++;
				}
				vis[ptr] = 1;
				if(!~nxt[ptr]) break;
				cpv = ptr;
				ptr = nxt[ptr];
			}
		}
		for(int i = 0; i < N; i++){
			moo << ans[i] << ' ';
		}
		moo << endl;
	}
}