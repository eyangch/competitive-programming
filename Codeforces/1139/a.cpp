#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N;
string S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> S;
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(S[i] % 2 == 0){
			ans += i+1;
		}
	}
	moo << ans << endl;
}