#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int T, N, M, K, Q;
int X[200000], Y[200000];
bool xd[200000], yd[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M >> K >> Q;
		fill(xd, xd+N, 0);
		fill(yd, yd+M, 0);
		for(int i = 0; i < Q; i++){
			eat >> X[i] >> Y[i];
			X[i]--, Y[i]--;
		}
		int xf = N, yf = M;
		int ans = 1;
		for(int i = Q-1; i >= 0; i--){
			bool bad = 0;
			bool xfl = xd[X[i]] || !yf;
			bool yfl = yd[Y[i]] || !xf;
			bad = (xfl && yfl);
			if(bad) continue;
			ans = (ans * K) % MOD;
			if(!xd[X[i]]){
				xd[X[i]] = 1, xf--;
			}
			if(!yd[Y[i]]){
				yd[Y[i]] = 1, yf--;
			}
		}
		moo << ans << endl;
	}
}