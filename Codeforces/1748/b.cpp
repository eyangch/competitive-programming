#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100000], add[10];
string S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> S;
		int ans = 0;
		for(int i = 0; i < N; i++){
			fill(add, add+10, 0);
			int occ = 0, mx = 0;
			for(int j = i; j < N && j < i + 102; j++){
				add[S[j]-'0']++;
				if(add[S[j]-'0'] == 1) occ++;
				mx = max(mx, add[S[j]-'0']);
				if(mx > 10) break;
				if(mx <= occ) ans++;
			}
		}
		moo << ans << endl;
	}
}