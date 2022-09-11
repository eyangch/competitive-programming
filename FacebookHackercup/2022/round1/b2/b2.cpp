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
			int pv = -1;
			for(int i = 0; i < N+Q; i++){
				int xat = 1e15, xbt = 1e15;
				if(!xa.empty()) xat = xa.top();
				if(!xb.empty()) xbt = xb.top();
				if(xat <= xbt){
					xa.pop();
					int odx = (dx + ddx) % MOD;
					int ndx = (dx + (xat - pv) * ddx) % MOD;
					int adx = (odx + ndx) * 500000004 % MOD;
					x = (x + adx * (xat - pv)) % MOD;
					dx = ndx;
					pv = xat;
					dx -= 1;
					ddx += 2;
				}else{
					xb.pop();
					int odx = (dx + ddx) % MOD;
					int ndx = (dx + (xbt - pv) * ddx) % MOD;
					int adx = (odx + ndx) * 500000004 % MOD;
					x = (x + adx * (xbt - pv)) % MOD;
					dx = ndx;
					pv = xbt;
					ans = (ans + x) % MOD;
				}
			}
			x = 0, dx = 0, ddx = 0, pv = 1e15;
			for(int i = 0; i < N+Q; i++){
				int xat = -1, xbt = -1;
				if(!xa2.empty()) xat = xa2.top();
				if(!xb2.empty()) xbt = xb2.top();
				if(xat >= xbt){
					xa2.pop();
					int odx = (dx + ddx) % MOD;
					int ndx = (dx + (pv - xat) * ddx) % MOD;
					int adx = (odx + ndx) * 500000004 % MOD;
					x = (x + adx * (pv - xat)) % MOD;
					dx = ndx;
					pv = xat;
					dx -= 1;
					ddx += 2;
				}else{
					xb2.pop();
					int odx = (dx + ddx) % MOD;
					int ndx = (dx + (pv - xbt) * ddx) % MOD;
					int adx = (odx + ndx) * 500000004 % MOD;
					x = (x + adx * (pv - xbt)) % MOD;
					dx = ndx;
					pv = xbt;
					ans = (ans + x) % MOD;
				}
			}
			swap(xa, ya);
			swap(xb, yb);
			swap(xa2, ya2);
			swap(xb2, yb2);
		}
		moo << ans << endl;
	}
}