#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, W, O, B, OW, BO, BW;

int cost(int x, int y, int a, int b){
	return x * a + y * b;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> W >> O >> B >> OW >> BO >> BW;
		OW = min(OW, BO + BW);
		BO = min(BO, OW + BW);
		BW = min(BW, OW + BO);
		int ans = 1e15;
		ans = min({cost(O, B, OW, BW), cost(W, O, BW, BO), cost(W, B, OW, BO)});
		moo << ans << endl;
	}
}