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
		int t = 0;
		for(int i = 0; i < N-1; i++){
			if(S[i] == 'L' && S[i+1] == 'R'){
				t = i+1;
			}
			if(S[i] == 'R' && S[i+1] == 'L'){
				t = -1;
				break;
			}
		}
		if(t == 0) moo << -1 << endl;
		if(t == -1) moo << 0 << endl;
		if(t > 0) moo << t << endl;
	}
}