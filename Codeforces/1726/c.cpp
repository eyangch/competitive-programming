#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;
string S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> S;
		int ans = 1;
		for(int i = 1; i < 2*N; i++){
			if(S[i] == '(' && S[i-1] == '(') ans++;
		}
		moo << ans << endl;
	}
}