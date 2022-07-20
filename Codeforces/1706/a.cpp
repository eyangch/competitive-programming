#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, A[50];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i]--;
		}
		string ans = "";
		for(int i = 0; i < M; i++) ans += 'B';
		for(int i = 0; i < N; i++){
			int x = A[i];
			int y = M - 1 - A[i];
			if(x > y) swap(x, y);
			if(ans[x] == 'B') ans[x] = 'A';
			else ans[y] = 'A';
		}
		moo << ans << endl;
	}
}