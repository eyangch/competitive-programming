#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100];
int dp[101][101][101];
int O = 0, E = 0;

int dpf(int o, int ou, int eu, int t){
	if(ou > O || eu > E){
		if(t == 0) return 1;
		else return -1;
	}
	if(dp[o][ou][eu]) return dp[o][ou][eu];
	if(ou == O && eu == E){
		//moo << 'f' << o << ' ' << ou << ' ' << eu << endl;
		if(o % 2){
			return (dp[o][ou][eu] = -1);
		}else{
			return (dp[o][ou][eu] = 1);
		}
	}
	int c = 0;
	if(!t){
		c = max(dpf(o+1, ou+1, eu, !t), dpf(o, ou, eu+1, !t));
	}else{
		c = min(dpf(o, ou+1, eu, !t), dpf(o, ou, eu+1, !t));
	}
	//moo << o << ' ' << ou << ' ' << eu << ' ' << c << endl;
	return (dp[o][ou][eu] = c);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		O = E = 0;
		for(int i = 0; i <= N; i++){
			for(int j = 0; j <= N; j++){
				for(int k = 0; k <= N; k++){
					dp[i][j][k] = 0;
				}
			}
		}
		for(int i = 0; i < N; i++){
			eat >> A[i];
			if(A[i] % 2){
				O++;
			}else{
				E++;
			}
		}
		int ans = dpf(0, 0, 0, 0);
		//moo << ans << endl;
		if(ans == 1){
			moo << "Alice" << endl;
		}else{
			moo << "Bob" << endl;
		}
	}
}