#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100000], mxc[100001];
bool Z[100001];
map<int, int> M;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		M.clear();
		for(int i = 0; i <= N; i++){
			Z[i] = 0;
			mxc[i] = -1;
		}
		set<int> ac;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			mxc[A[i]] = i;
		}
		int ans = 0;
		int mxz = -1;
		int mn = A[N-1];
		for(int i = N-2; i >= 0; i--){
			if(A[i] > mn){
				mxz = i;
				break;
			}
			mn = A[i];
		}
		for(int i = 0; i < N; i++){
			if(i > mxz) break;
			if(Z[A[i]]) continue;
			mxz = max(mxz, mxc[A[i]]);
			Z[A[i]] = 1;
			ans++;
		}
		moo << ans << endl;
	}
}