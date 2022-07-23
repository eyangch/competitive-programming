#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;
string s;
int amt[128];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> s;
		for(int i = 0; i < 128; i++) amt[i] = 0;
		for(int i = 0; i < N; i++){
			amt[s[i]]++;
		}
		int ans = 0;
		for(int i = 0; i < 128; i++){
			if(amt[i] > 0) ans += amt[i] + 1;
		}
		moo << ans << endl;
	}
}