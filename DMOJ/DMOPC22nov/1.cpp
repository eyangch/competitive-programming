#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N;
char S[200001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	fill(S, S+N, '_');
	int ans = 0;
	for(int i = 0; i < N; i += 4){
		int d = min(4LL, N - i);
		if(d == 4){
			S[i+1] = S[i+2] = 'M';
			ans += 2;
		}
		if(d == 3){
			S[i+1] = 'M';
			ans++;
		}
	}
	moo << ans << endl << S << endl;
}