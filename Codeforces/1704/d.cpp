#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;
vector<int> C[100000], P[100000], D[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i < N; i++){
			C[i].clear(), P[i].clear(), D[i].clear();
			for(int j = 0; j < M; j++){
				int x; eat >> x;
				C[i].push_back(x);
				P[i].push_back(x);
				if(j > 0) P[i][j] += P[i][j-1];
			}
		}
		int ans1 = 0, ans2 = 0;
		for(int i = 1; i < N; i++){
			int sum = 0;
			for(int j = 0; j < M; j++){
				sum += P[0][j] - P[i][j];
			}
			if(sum < 0){
				ans1 = 1, ans2 = -sum;
			}else if(sum > 0){
				ans1 = i+1, ans2 = sum;
			}
		}
		moo << ans1 << ' ' << ans2 << endl;
	}
}