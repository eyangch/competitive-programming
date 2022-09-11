#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[500000], B[500000], Q, X[500000], Y[500000], MOD = 1e9+7;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> N;
		priority_queue<int, vector<int>, greater<int>> xa, xb, ya, yb;
		priority_queue<int> xa2, xb2, ya2, yb2;
		for(int i = 0; i < N; i++){
			eat >> A[i] >> B[i];
			xa.push(A[i]);
			ya.push(B[i]);
			xa2.push(A[i]);
			ya2.push(B[i]);
		}
		eat >> Q;
		for(int i = 0; i < Q; i++){
			eat >> X[i] >> Y[i];
			xb.push(X[i]);
			yb.push(Y[i]);
			xb2.push(X[i]);
			yb2.push(Y[i]);
		}
		int ans = 0;
		for(int swapxy = 0; swapxy < 2; swapxy++){
			int x = 0, dx = 0, ddx = 0;
			for(int i = 0; i <= 3000; i++){
				while(!xa.empty() && xa.top() == i){
					dx -= 1;
					ddx += 2;
					xa.pop();
				}
				while(!xb.empty() && xb.top() == i){
					ans = (ans + x) % MOD;
					//moo << x << "    " << dx << ' ' << ddx << endl;
					xb.pop();
				}
				//moo << x << ' ' << dx << ' '<< ddx << endl;
				dx = (dx + ddx) % MOD;
				x = (x + dx) % MOD;
			}
			x = 0, dx = 0, ddx = 0;
			for(int i = 3000; i >= 0; i--){
				while(!xa2.empty() && xa2.top() == i){
					dx -= 1;
					ddx += 2;
					xa2.pop();
				}
				while(!xb2.empty() && xb2.top() == i){
					ans = (ans + x) % MOD;
					//moo << x << "    " << dx << ' ' << ddx << endl;
					xb2.pop();
				}
				dx = (dx + ddx) % MOD;
				x = (x + dx) % MOD;
			}
			swap(xa, ya);
			swap(xb, yb);
			swap(xa2, ya2);
			swap(xb2, yb2);
		}
		moo << ans << endl;
	}
}